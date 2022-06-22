//gcc 7.4.0

#include  <stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock;
int counter=0;

void *thread(void *arg){
    pthread_mutex_lock(&lock);
    int i=0;
    counter++;
    printf("\nJob %d is started",counter);
    for(i=0;i<10000;i++);
    printf("\nJob %d is finished",counter);
    pthread_mutex_unlock(&lock);
}

int main(void)
{
    pthread_t t1,t2;
    pthread_mutex_init(&lock,NULL);
    pthread_create(&t1,NULL,&thread,NULL);
    pthread_create(&t2,NULL,&thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
