/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104


*********************Assignment No. 5************************************
AIM:- Thread synchronization and mutual exclusion using mutex. Application to demonstrate:
     Reader-Writer problem with reader priority.**************/


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t mutex,writeblock;
int data=0,rcount=0;

void *reader(void*arg)
{
 int f;
 f=((long int)arg);
 sem_wait(&mutex);
 rcount=rcount+1;
 if(rcount==1)
 sem_wait(&writeblock);
 sem_post(&mutex);
printf("Data read by the reader %d is %d\n",f,data);
sleep(1);
sem_wait(&mutex);
rcount=rcount-1;
if(rcount==0)
sem_post(&writeblock);
sem_post(&mutex);

}
void *writer(void *arg)
{
 int f;
f=((long int)arg);
sem_wait(&writeblock);
data++;
printf("Data written by the writer %d is %d\n",f,data);
sleep(1);
sem_post(&writeblock);
}


int main()
{
int i,b;
int pr;
pthread_t rtid[10],wtid[10];
sem_init(&mutex,0,1);
sem_init(&writeblock,0,1);
printf("Enter the no. of process you want to create");
scanf("%d",&pr);
for(i=0;i<=pr;i++)
{
 pthread_create(&wtid[i],NULL,writer,(void*)(long) i);
 pthread_create(&rtid[i],NULL,reader,(void*)(long) i);

}

for(i=0;i<=pr;i++)
{

pthread_join(wtid[i],NULL);
 pthread_join(rtid[i],NULL);

}

}

/********************************OUTPUT*********************
spllab01@spllab01-Vostro-3268:~$ gcc ass5.c -lpthread

spllab01@spllab01-Vostro-3268:~$ ./a.out

Enter the no. of process you want to create 10

Data read by the reader 0 is 0

Data read by the reader 1 is 0

Data read by the reader 3 is 0

Data read by the reader 2 is 0

Data read by the reader 4 is 0

Data read by the reader 5 is 0

Data read by the reader 6 is 0

Data read by the reader 9 is 0

Data read by the reader 8 is 0

Data read by the reader 10 is0

Data read by the reader 7 is 0

Data written by the writer 1 is 1

Data written by the writer 2 is 2

Data written by the writer 0 is 3

Data written by the writer 6 is 4

Data written by the writer 4 is 5

Data written by the writer 3 is 6

Data written by the writer 5 is 7

Data written by the writer 7 is 8

Data written by the writer 8 is 9

Data written by the writer 10 is 10

Data written by the writer 9 is 11

**/
