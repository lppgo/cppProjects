package main

import (
	"context"
	"log"
	"os"
	"time"

	pb "ama.grpc.go/pb"
	"google.golang.org/grpc"
)

const (
	address     = "localhost:50051"
	defaultName = "world"
)

/*

protoc v3
go plugins :
	go install google.golang.org/protobuf/cmd/protoc-gen-go@v1.26
	go install google.golang.org/grpc/cmd/protoc-gen-go-grpc@v1.1


proto文件

protoc \
-I=./protos \
--go_out=./go/pb/ --go_opt=paths=source_relative \
--go-grpc_out=./go/pb/ --go-grpc_opt=paths=source_relative \
protos/AMAServer.proto


*/

func main() {
	// Set up a connection to the server.
	conn, err := grpc.Dial(address, grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()
	c := pb.NewAMAServerClient(conn)

	// Contact the server and print out its response.
	str := "2021-11-01 18:00:00"
	if len(os.Args) > 1 {
		str = os.Args[1]
	}
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()
	r, err := c.MDOrderBook(ctx, &pb.MDOrderBookRequest{ReqTime: str})
	if err != nil {
		log.Fatalf("could not greet: %v", err)
	}
	log.Printf("Greeting: %#v", r.GetOrderBookVector()[0])
}
