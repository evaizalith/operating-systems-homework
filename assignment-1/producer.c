//producer.c

//This program produces output to be read by a consumer process
//found in consumer.c

//Takes in 2 integers from the user
//Input is passed to the consumer, which adds them together and prints the value

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

sem_t semaphore; 
int shmid;

struct buffer_t {
    int table[2];
};

buffer_t *buffer; 

int main() {    
    shmid = shmget(10312022, sizeof(buffer_t), 0666 | IPC_CREAT); //create shared memory
    buffer = (buffer_t*)shmat(shmid, NULL, 0); //attach to shared memory segment 

    for(int i = 0; i < 2; i++) {
        printf("Enter integer #%d: ", i);
        scanf("%d", &buffer.table[i]);
    }

    printf("Input received! Sending to consumer...\n");
    

    return 0;
}