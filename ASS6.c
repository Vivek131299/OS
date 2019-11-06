
/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

******************************Assignment No. 6********************************
AIM :-Deadlock Avoidance Using Semaphores: Implement the deadlock-free solution to Dining
  Philosophers problem to illustrate the problem of deadlock and/or starvation that can occur when     many synchronized threads are competing for limited resources.
*/

#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>


#define n 5
#define thinking 0
#define hungry 1
#define eating 2
#define left (ph_num + 4)%n
#define right (ph_num + 1)%n

sem_t room;
sem_t chopst[n];

void *philosopher(void *num);
void take_chopst(int);
void put_chopst(int);
void test(int);

int state[n];
int ph_num[n]={0,1,2,3,4};

int main()
{
int i; 
pthread_t thread_id[n];
sem_init(&room,0,1);
for(i=0;i<n;i++)
sem_init(&chopst[i],0,0);
for(i=0;i<n;i++)
{
pthread_create(&thread_id[i],NULL,philosopher,&ph_num[i]);
printf("Philosopher %d is thinking \n",i+1);
}
for(i=0;i<n;i++)
{
pthread_join(thread_id[i],NULL);
}
sem_destroy(&chopst[n]);
sem_destroy(&room);
pthread_exit(0);
}

void *philosopher(void *num)
{
int x=1;
while(x<5)
{
int *i=num;
usleep(1);
take_chopst(*i);
usleep(1);
put_chopst(*i);
x++;
}
}


void take_chopst(int ph_num)
{
sem_wait(&room);
state[ph_num]=hungry;
printf("philosopher %d is hungry \n",ph_num+1);
test(ph_num);
sem_post(&room);
sem_wait(&chopst[ph_num]);
usleep(1);
}

void test(int ph_num)
{
if(state[ph_num]==hungry && state[left]!=eating && state[right]!=eating)
{
state[ph_num]=eating;
usleep(10);
printf("philosopher %d takes lesft chopstick %d and right chopstick %d \n",ph_num+1,left+1,ph_num+1);
printf("philosopher %d is eating \n",ph_num+1);
sem_post(&chopst[ph_num]);
}
}

void put_chopst(int ph_num)
{
sem_wait(&room);
state[ph_num]=thinking;
printf("philosopher %d putting %d anf %d chopstick down\n",ph_num+1,left+1,ph_num+1);
printf("philosopher %d is thinking \n",ph_num+1);
test(left);
test(right);
sem_post(&room);
}



/*********************************OUTPUT****************************************
Philosopher 1 is thinking 
Philosopher 2 is thinking 
Philosopher 3 is thinking 
philosopher 1 is hungry 
Philosopher 4 is thinking 
Philosopher 5 is thinking 
philosopher 1 takes lesft chopstick 5 and right chopstick 1 
philosopher 1 is eating 
philosopher 5 is hungry 
philosopher 2 is hungry 
philosopher 4 is hungry 
philosopher 4 takes lesft chopstick 3 and right chopstick 4 
philosopher 4 is eating 
philosopher 3 is hungry 
philosopher 1 putting 5 anf 1 chopstick down
philosopher 1 is thinking 
philosopher 2 takes lesft chopstick 1 and right chopstick 2 
philosopher 2 is eating 
philosopher 4 putting 3 anf 4 chopstick down
philosopher 4 is thinking 
philosopher 5 takes lesft chopstick 4 and right chopstick 5 
philosopher 5 is eating 
philosopher 2 putting 1 anf 2 chopstick down
philosopher 2 is thinking 
philosopher 3 takes lesft chopstick 2 and right chopstick 3 
philosopher 3 is eating 
philosopher 1 is hungry 
philosopher 4 is hungry 
philosopher 5 putting 4 anf 5 chopstick down
philosopher 5 is thinking 
philosopher 1 takes lesft chopstick 5 and right chopstick 1 
philosopher 1 is eating 
philosopher 2 is hungry 
philosopher 3 putting 2 anf 3 chopstick down
philosopher 3 is thinking 
philosopher 4 takes lesft chopstick 3 and right chopstick 4 
philosopher 4 is eating 
philosopher 5 is hungry 
philosopher 1 putting 5 anf 1 chopstick down
philosopher 1 is thinking 
philosopher 2 takes lesft chopstick 1 and right chopstick 2 
philosopher 2 is eating 
philosopher 3 is hungry 
philosopher 4 putting 3 anf 4 chopstick down
philosopher 4 is thinking 
philosopher 5 takes lesft chopstick 4 and right chopstick 5 
philosopher 5 is eating 
philosopher 2 putting 1 anf 2 chopstick down
philosopher 2 is thinking 
philosopher 3 takes lesft chopstick 2 and right chopstick 3 
philosopher 3 is eating 
philosopher 1 is hungry 
philosopher 4 is hungry 
philosopher 5 putting 4 anf 5 chopstick down
philosopher 5 is thinking 
philosopher 1 takes lesft chopstick 5 and right chopstick 1 
philosopher 1 is eating 
philosopher 2 is hungry 
philosopher 3 putting 2 anf 3 chopstick down
philosopher 3 is thinking 
philosopher 4 takes lesft chopstick 3 and right chopstick 4 
philosopher 4 is eating 
philosopher 5 is hungry 
philosopher 1 putting 5 anf 1 chopstick down
philosopher 1 is thinking 
philosopher 2 takes lesft chopstick 1 and right chopstick 2 
philosopher 2 is eating 
philosopher 3 is hungry 
philosopher 4 putting 3 anf 4 chopstick down
philosopher 4 is thinking 
philosopher 5 takes lesft chopstick 4 and right chopstick 5 
philosopher 5 is eating 
philosopher 1 is hungry 
philosopher 2 putting 1 anf 2 chopstick down
philosopher 2 is thinking 
philosopher 3 takes lesft chopstick 2 and right chopstick 3 
philosopher 3 is eating 
philosopher 4 is hungry 
philosopher 5 putting 4 anf 5 chopstick down
philosopher 5 is thinking 
philosopher 1 takes lesft chopstick 5 and right chopstick 1 
philosopher 1 is eating 
philosopher 3 putting 2 anf 3 chopstick down
philosopher 3 is thinking 
philosopher 4 takes lesft chopstick 3 and right chopstick 4 
philosopher 4 is eating 
philosopher 2 is hungry 
philosopher 1 putting 5 anf 1 chopstick down
philosopher 1 is thinking 
philosopher 2 takes lesft chopstick 1 and right chopstick 2 
philosopher 2 is eating 
philosopher 5 is hungry 
philosopher 3 is hungry 
philosopher 4 putting 3 anf 4 chopstick down
philosopher 4 is thinking 
philosopher 5 takes lesft chopstick 4 and right chopstick 5 
philosopher 5 is eating 
philosopher 2 putting 1 anf 2 chopstick down
philosopher 2 is thinking 
philosopher 3 takes lesft chopstick 2 and right chopstick 3 
philosopher 3 is eating 
philosopher 5 putting 4 anf 5 chopstick down
philosopher 5 is thinking 
philosopher 3 putting 2 anf 3 chopstick down
philosopher 3 is thinking 
*/
