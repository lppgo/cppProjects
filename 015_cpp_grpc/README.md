https://blog.csdn.net/iamanda/article/details/112539366

# 1

- 可在 ubuntu 上成功执行(需要安装 grpc)，执行`make`后生成可执行文件`server`和`client`。然后分别在不同的 terminal 运行`./server`和`./client`。
- service 定义的 information.proto 中
- server 的实现在 server.cc 中
- client 的实现在 client.cc 中

# 2 empty

## 2.1 proto

```proto3
import "google/protobuf/empty.proto";

...
service Manager {
    // unary rpc
    rpc AddRecord (Person) returns (google.protobuf.Empty) {}

    // stream grpc
    rpc DeleteRecords (stream ReqName) returns (google.protobuf.Empty) {}
    rpc GetRecordsByAge (AgeRange) returns (stream Person) {}
    rpc GetRecordsByNames (stream ReqName) returns (stream Person) {}
}


```

## 2.2 client

```cpp
#include "information.grpc.pb.h"

#include <grpcpp/grpcpp.h>

    void GetRecordsByAge(int min, int max) {
        info::AgeRange range;
        range.set_minimal(min);
        range.set_maximal(max);

        grpc::ClientContext context;
        std::unique_ptr<grpc::ClientReader<info::Person>> reader(stub_->GetRecordsByAge(&context, range));

        info::Person person;
        while(reader->Read(&person)) {
            std::cout << "get person:" << std::endl;
            printPerson(person);
        }
        grpc::Status status = reader->Finish();
        handleStatus(status, __func__);
    }
```

## 2.3 server

```cpp
#include "information.grpc.pb.h"

#include <grpcpp/grpcpp.h>

    grpc::Status GetRecordsByAge(grpc::ServerContext * context,
                                 const info::AgeRange * range,
                                 grpc::ServerWriter<info::Person> * writer) override {
        int min = range->minimal();
        int max = range->maximal();

        for(const auto &person : person_list_) {
            auto age = person.age();
            if (age >= min && age <= max ) {
                writer->Write(person);
            }
        }
        return grpc::Status::OK;
    }
```
