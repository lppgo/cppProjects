[toc]

# 1: grpc,cpp 环境

https://grpc.io/docs/languages/cpp/

`注意gcc版本`

# 2: start

## 2.1 xxx.proto

- ## 编写 protoc
- protoc 生成`xxx.pb.h`,`xxx.pb.cc`,`xxx.grpc.pb.h`,`xxx.grpc.pb.c`文件

```bash
protoc \
-I=./protos \
--cpp_out=. \
--grpc_out=. \
--plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
AMAServer.proto


protoc -I=./protos --cpp_out=./include helloworld.proto

protoc -I=./protos --grpc_out=./include \
--plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto
```

## 2.2 server.cpp

## 2.3 client.cpp

## 2.4 编译链接

### 2.4.1 源码方式

```bash
g++ -std=c++11 \
-L=/usr/lib \
-L=/usr/local/lib \
-L=/home/lucas/.local/lib \
-I=. \
-I=./include \
-I=/mnt/e/cppProjects001/007_cppgrpc/include \
-I=/home/lucas/.local/include \
`pkg-config --libs protobuf grpc++` \
-pthread -Wl,--no-as-needed \
-lgrpc++_reflection -Wl,--as-needed -ldl \
./include/helloworld.pb.cc \
./include/helloworld.grpc.pb.cc \
greeter_server.cc \
-o greeter_server


g++ -std=c++11 \
-L=/usr/lib \
-L=/usr/local/lib \
-L=/home/lucas/.local/lib \
-I=/mnt/e/cppProjects001/007_cppgrpc/include \
`pkg-config --libs protobuf grpc++` \
-pthread -Wl,--no-as-needed \
-lgrpc++_reflection -Wl,--as-needed -ldl \
./include/helloworld.pb.cc \
./include/helloworld.grpc.pb.cc \
greeter_server.cc \
-o greeter_server

```

### 2.4.2 使用`.o`目标文件

### 2.2.1 xxx.cpp 源码编译链接

// compiler 编译 （.o）

```bash
# helloworld.pb.cc
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  \
-c -o ./lib/helloworld.pb.o \
./include/helloworld.pb.cc

# helloworld.grpc.pb.cc
g++ -std=c++11 `pkg-config --cflags protobuf grpc`  \
-c -o ./lib/helloworld.grpc.pb.o \
./include/helloworld.grpc.pb.cc

# greeter_client
g++ -std=c++11 `pkg-config --cflags protobuf grpc` -c -o \
greeter_client.o greeter_client.cc

g++ \
-L/usr/lib \
-L/usr/local/lib \
`pkg-config --libs protobuf grpc++` \
-pthread -Wl,--no-as-needed \
-lgrpc++_reflection -Wl,--as-needed -ldl \
helloworld.pb.o helloworld.grpc.pb.o greeter_client.o \
-o greeter_client

# greeter_server
g++ -std=c++11 `pkg-config --cflags protobuf grpc` \
-c -o greeter_server.o greeter_server.cc

g++ \
-L/usr/lib -L/usr/local/lib \
`pkg-config --libs protobuf grpc++` \
-pthread -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed -ldl \
helloworld.pb.o helloworld.grpc.pb.o greeter_server.o \
-o greeter_server


```

## 2.4 g++

- cpp 源码

```bash
g++ helloworld.pb.cc helloworld.grpc.pb.cc greeter_server.cc \
-L/usr/local/lib \
-L/usr/lib \
-I . \
-I /usr/include \
-I /home/lucas/.local/include \
`pkg-config --libs protobuf grpc++` \
-pthread -Wl,--no-as-needed \
-lgrpc++_reflection -Wl,--as-needed -ldl \
-o greeter_server


```

```bash





```

protoc -I ./protos --cpp_out=. ./protos/helloworld.proto

protoc -I ./protos --grpc_out=. --plugin=protoc-gen-grpc=/home/lucas/.local/bin/grpc_cpp_plugin ./protos/helloworld.proto

g++ -std=c++11 `pkg-config --cflags protobuf grpc` -c -o helloworld.pb.o helloworld.pb.cc

g++ -std=c++11 `pkg-config --cflags protobuf grpc` -c -o helloworld.grpc.pb.o helloworld.grpc.pb.cc

g++ helloworld.pb.o helloworld.grpc.pb.o greeter_client.o -L/usr/lib -L/usr/local/lib `pkg-config --libs protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++\_reflection -Wl,--as-needed -ldl -o greeter_client

g++ helloworld.pb.o helloworld.grpc.pb.o greeter_server.o -L/usr/lib -L/usr/local/lib `pkg-config --libs protobuf grpc++` -pthread -Wl,--no-as-needed -lgrpc++\_reflection -Wl,--as-needed -ldl -o greeter_server
