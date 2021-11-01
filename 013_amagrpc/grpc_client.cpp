#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "AMAServer.grpc.pb.h"

using AMA::AMAServer;
using AMA::MDOrderBookRequest;
using AMA::MDOrderBookResponse;
using AMA::MDOrderBook;
using AMA::MDOrderBookItem;

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using grpc::Status;

class AMAServerClient {
 public:
  AMAServerClient(std::shared_ptr<Channel> channel)
      : stub_(AMAServer::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string MDOrderBook(const std::string& req) {
    // Data we are sending to the server.
    MDOrderBookRequest request;
    request.set_req_time(req);

    // Container for the data we expect from the server.
    MDOrderBookResponse reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->MDOrderBook(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
      return "ok";
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<AMAServer::Stub> stub_;
};

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target="
                  << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:50051";
  }
  AMAServerClient AMAClient(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));
  std::string req_time("20211101");
  std::string reply = AMAClient.MDOrderBook(req_time);
  std::cout << "MDOrderBook Service reply.size: " << reply.size() << std::endl;

  return 0;
}