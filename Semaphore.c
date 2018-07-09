#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;
void * thread(int id){
    sem_wait(&semaphore);
    //Critical Section
    printf("Inside Critical Section. %d\n",id);
    sleep(5);
    printf("Leaving Critical Section. %d\n",id);
    sem_post(&semaphore);
}
int main()
{
    sem_init(&semaphore,0,2);
    pthread_t t1,t2,t3,t4;
    pthread_create(&t1,NULL,thread,1);
    sleep(1);
    pthread_create(&t2,NULL,thread,2);
    sleep(1);
    pthread_create(&t3,NULL,thread,3);
    sleep(1);
    pthread_create(&t4,NULL,thread,4);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    sem_destroy(&semaphore);
    return 0;
}
