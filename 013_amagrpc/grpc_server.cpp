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

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Logic and data behind the server's behavior.
class AMAServerImpl final : public AMAServer::Service {
  Status MDOrderBook(ServerContext* context, const MDOrderBookRequest* request,
                  MDOrderBookResponse* response) override {
      std::cout << "requestTime:" << request->req_time() << std::endl;

    //   MDOrderBookResponse order_book_vector;
    //   MDOrderBook order_book;
    //   MDOrderBookItem order_book_item;

    //   order_book_item.set_price(100);
    //   order_book_item.set_volume(100100);
    //   order_book_item.set_order_queue(0,99);
    //   order_book_item.set_order_queue(1,999);

    //   order_book.set_security_code(601818);
    //   order_book.set_channel_no(101);
    //   order_book.add_bid_order_book(order_book_item);

    //   order_book_vector[0] = order_book;
    //   response->add_order_book_vector(order_book_vector);

      response->add_order_book_vector();
      //   response->set_channel_no(999);
      //   MDOrderBookResponse new orderbooks;

      //   response = orderbooks;

      return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  AMAServerImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}