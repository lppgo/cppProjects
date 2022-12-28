#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>


#define BUFFER 1024

int main(int argc,char *argv[]) {
    std::cout << "IPC是共享内存通信..." << std::endl;
    std::cout <<"这是shm writer 进程..."<< std::endl;

    // 创建一个新的共享内存段或者取得一个已有的共享内存段的标识符
    int shmid=shmget((key_t)123456,BUFFER,S_IRUSR|S_IWUSR|IPC_CREAT|IPC_EXCL);
    if (shmid==-1){
        perror("shmget error");
        exit(1);
    }
    std::cout << "shmid = "<< shmid<< std::endl;
    printf("shmid = %d\n",shmid);
    // 将共享内存段加载到调用进程的虚拟地址空间中
    char* shmaddr=(char*)shmat(shmid,NULL,0);
    if (shmaddr == (void*)-1){
        perror("shmat error");
        exit(1);
    }

    // 从标准输入读数据
    fgets(shmaddr,100,stdin);
    // 分离共享内存段
    if(shmdt(shmaddr)==-1){
        perror("shmdt error");
        exit(1);
    }

    sleep(30);// sleep 30秒
    // 删除这块共享内存
    if(shmctl(shmid,IPC_RMID,NULL)==-1){
        perror("shmctl");
        exit(1);
    }
    std::cout<<"shmctl deconstruction IPC ..."<<std::endl;
    std::cout<<"writer exit ..."<<std::endl;
    return 0;
}
