#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/shm.h>

#define BUFFER 1024

int main(int argc,char* argv[]) {
    std::cout << "IPC (Inter-Process Communication)" << std::endl;
    std::cout<<"这是shm reader进程..."<<std::endl;

    int shmid=shmget((key_t)123456,BUFFER,S_IRUSR|S_IWUSR);
    if(shmid==-1){
        perror("shmget error");
        exit(1);
    }

    char* shmaddr=(char*)shmat(shmid,NULL,0);
    if (shmaddr==(void*)-1){
        perror("shmat error");
        exit(1);
    }

    // 输出从另一个进程传过来的数据
    printf("%s\n",shmaddr);
    if(shmdt(shmaddr)==-1){
        perror("shmdt");
        exit(1);
    }

    return 0;
}
