/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

********************Assignment No. 4 *******************************
AIM:- Thread synchronization using counting semaphores. Application to demonstrate:
  producer-consumer problem with counting semaphores and mutex.*************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h>

#define SIZE 10
#define NUMB_THREADS 10
#define PRODUCER_LOOPS 2
#define CONSUMER_LOOPS 2
  
#define TRUE 1
#define FALSE 0
 
typedef int buffer_t;
buffer_t buffer[SIZE];
int buffer_index;
  
pthread_mutex_t buffer_mutex;

sem_t full_sem;  
sem_t empty_sem; 
  
void insertbuffer(buffer_t value) {
    if (buffer_index < SIZE) {
        buffer[buffer_index++] = value;
    } else {
        printf("Buffer overflow\n");
    }
}
  
buffer_t dequeuebuffer() {
    if (buffer_index > 0) {
        return buffer[--buffer_index]; 
    } else {
        printf("Buffer underflow\n");
    }
    return 0;
}
   
int isempty() {
    if (buffer_index == 0)
        return TRUE;
    return FALSE;
}
  
int isfull() {
    if (buffer_index == SIZE)
        return TRUE;
    return FALSE;
}
 
void *producer2(void *thread_n) {
    int thread_numb = *(int *)thread_n;
    buffer_t value;
    int i=0;
    while (i++ < PRODUCER_LOOPS) {
        sleep(rand() % 10);
        value = rand() % 100;
        pthread_mutex_lock(&buffer_mutex);
        do {
            
            pthread_mutex_unlock(&buffer_mutex);
            
            sem_wait(&full_sem); 
            pthread_mutex_lock(&buffer_mutex);
        } while (isfull()); 
        insertbuffer(value);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty_sem); 
        printf("Producer %d added %d to buffer\n", thread_numb, value);
    }
    pthread_exit(0);
}
  
void *consumer2(void *thread_n) {
    int thread_numb = *(int *)thread_n;
    buffer_t value;
    int i=0;
    while (i++ < CONSUMER_LOOPS) {
        pthread_mutex_lock(&buffer_mutex);
        do {
            pthread_mutex_unlock(&buffer_mutex);
            sem_wait(&empty_sem);
            pthread_mutex_lock(&buffer_mutex);
        } while (isempty()); 
        value = dequeuebuffer(value);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full_sem); 
        printf("Consumer %d dequeue %d from buffer\n", thread_numb, value);
   }
    pthread_exit(0);
}
  
int main(int argc, int **argv) {
    buffer_index = 0;
    int thread_numb[NUMB_THREADS];
    int i;
  
    pthread_mutex_init(&buffer_mutex, NULL);
    sem_init(&full_sem, 0,SIZE); 
    sem_init(&empty_sem,  0,0);
    pthread_t thread[NUMB_THREADS];
   
	
    for (i = 0; i < NUMB_THREADS; ) {
        thread_numb[i] = i;
        pthread_create(thread + i, NULL,producer2, thread_numb + i);  
        i++;
        thread_numb[i] = i;
       
        pthread_create(&thread[i], NULL, consumer2, &thread_numb[i]); 
        i++;
    }
  
    for (i = 0; i < NUMB_THREADS; i++)
        pthread_join(thread[i], NULL);
  
    pthread_mutex_destroy(&buffer_mutex);
    sem_destroy(&full_sem);
    sem_destroy(&empty_sem);
  
    return 0;
}

/*****************************OUTPUT**************************

spllab01@spllab01-Vostro-3268:~$ gcc ass4.c -lpthread
spllab01@spllab01-Vostro-3268:~$ ./a.out
Producer 0 added 35 to buffer
Producer 8 added 92 to buffer
Consumer 1 dequeue 35 from buffer
Consumer 3 dequeue 92 from buffer
Producer 6 added 21 to buffer
Consumer 5 dequeue 21 from buffer
Producer 2 added 27 to buffer
Consumer 7 dequeue 27 from buffer
Producer 2 added 59 to buffer
Consumer 9 dequeue 59 from buffer
Producer 4 added 63 to buffer
Consumer 1 dequeue 63 from buffer
Producer 6 added 40 to buffer
Consumer 3 dequeue 40 from buffer
Producer 0 added 26 to buffer
Consumer 5 dequeue 26 from buffer
Producer 8 added 72 to buffer
Consumer 7 dequeue 72 from buffer
Producer 4 added 36 to buffer
Consumer 9 dequeue 36 from buffer
*/

