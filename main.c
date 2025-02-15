#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *routine(){
    printf("Test from threads\n");
    sleep(3);
    printf("Ending threads\n");
}

int main(int args, char *argv[]){
    pthread_t t1, t2;

    if(pthread_create(&t1, NULL, &routine, NULL)!=0)
        return 1;
    if(pthread_create(&t2, NULL, &routine, NULL) !=0)
        return 2;

    if(pthread_join(t1, NULL) !=0)
        return 4;         // wait for threads
    if(pthread_join(t2, NULL) !=0)
        return 5;
    return 0;
}