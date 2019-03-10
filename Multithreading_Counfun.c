#include<stdio.h>
#include<pthread.h>

#define NUMBEROFCOUNT 5000000
long long sum=0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * counting_threadfun(void *arg)
{
    int offset = *(int *)arg;
    for(int i=0;i<NUMBEROFCOUNT;i++)
    {
        //Starts Critical Section
        pthread_mutex_lock(&lock);
        sum+=offset;
        pthread_mutex_unlock(&lock);
        //End of Critical section
    }

    pthread_exit(NULL);
}

int main()
{
    //Swan threads
    pthread_t t1,t2;

    int offset1=1;
    pthread_create(&t1,NULL,counting_threadfun,&offset1);

    int offset2=-2;
    pthread_create(&t2,NULL,counting_threadfun,&offset2);

    //wait for threads to finish
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    printf("Sum=%lld",sum);

    return 0;
}
