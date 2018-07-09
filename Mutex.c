
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int counter=0;
pthread_mutex_t lock;

void thread(int id){
    pthread_mutex_lock(&lock);
    counter+=1;
    printf("For ID %d Counter %d\n",id,counter);
    sleep(5);
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t t1,t2,t3;
    if(pthread_mutex_init(&lock,NULL)!=0){
        printf("Mutex Init Failed");
        return 1;
    }
    pthread_create(&t1,NULL,thread,1);
    pthread_create(&t2,NULL,thread,2);
    pthread_create(&t3,NULL,thread,3);
    
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    pthread_mutex_destroy(&lock);
}
