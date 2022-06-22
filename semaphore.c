//during compilation it is very important to give -pthread
/*
gcc semaphore.c -pthread
./a.out
*/
#include  <stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
sem_t mutex;
void *thread(void *arg){
    sem_wait(&mutex);
    printf("\nEntered....");
    sleep(4);
    printf("Just exiting...");
    sem_post(&mutex);
}

int main(void)
{
    sem_init(&mutex,0,1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}
