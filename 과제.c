#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<pthread.h>
#include<signal.h>
int sum;
int fd,s;
char *buf;
int i=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void*sum1(void*num){
    int n=*((int*)num);
    for(;i<n;){
        pthread_mutex_lock(&mutex);
        sum++;
        s=write(fd,buf+i,1);
        printf("thread1\n");
        i+=1;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
void*sum2(void*num){
    int n=*((int*)num);
    for(;i<n;){
        pthread_mutex_lock(&mutex);
        sum++;
        s=write(fd,buf+i,1);
        printf("thread2\n");
        i+=1;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void sigHandler(int sig){
    int thread;
    pthread_t p_thread[2];

    fd=open("file1.txt",O_CREAT|O_RDWR|O_TRUNC,0644);
    if(fd<0){
        printf("file open error\n");
    }
    
    int sts;
    int arg;
    
    sum=0;
    arg=strlen(buf);

    thread=pthread_create(&p_thread[0],NULL,sum1,(void*)&arg);
    thread=pthread_create(&p_thread[1],NULL,sum2,(void*)&arg);
    pthread_join(p_thread[0],(void**)&sts);

    pthread_join(p_thread[1],(void**)&sts);
    
    sts=pthread_mutex_destroy(&mutex);
    exit(1);
}
int main(){
    
    
    buf=(char*)malloc(sizeof(char)*256);
    
    signal(SIGINT,sigHandler);

    while(1){
        buf[strlen(buf)]='\n';
        scanf("%[^\n]s",buf+strlen(buf));
        getchar();
    }
     
   
}
