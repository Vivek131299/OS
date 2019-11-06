/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

***********************************Assignment No. 8******************************************
 AIM:-Inter-process Communication using Shared Memory using System V. Application to
 demonstrate: Client and Server Programs in which server process creates a shared memory segment and
 writes the message to the shared memory segment. Client process reads the message from the shared
 memory segment and displays it to the screen.***/

/* SERVER PROGRAM
  client=tea
  server=milk*/


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMSZ 27

main()
{
char c;
int shmid;
key_t key;
char *shm,*s;
key=5678;
 if((shmid=shmget(key,SHMSZ,IPC_CREAT |0666))<0)
{
perror("shmget");
exit(0);
}

if((shm=shmat(shmid,NULL,0))==(char *)-1)
{
perror("shmat");
exit(0);
}

s=shm;

for(c='a'; c<='z';c++)
*s++=c;
*s='\0';
while(*shm!='*')
sleep(1);
exit(0);
}



/*dslab@ds-dx2480-MT:~$ gcc milk.c
dslab@ds-dx2480-MT:~$ ./a.out*/


/******************CLIENT***************/
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
//#include<iostream.h>
#define SHMSZ 27

main()
{
int shmid;
key_t key=5678;
char *shm,*s;
 if((shmid=shmget(key,SHMSZ,0666))<0)
{
perror("shmget");
exit(0);
}

if((shm=shmat(shmid,NULL,0))==(char *)-1)
{
perror("shmat");
exit(0);
}
for (s=shm; *s!='\0';s++)
putchar(*s);
putchar('\n');
shm='*';
exit(0);
}



/***************************OUTPUT***************************************


dslab@ds-dx2480-MT:~$ gcc tea.c
tea.c: In function �main�:
tea.c:28:4: warning: assignment makes pointer from integer without a cast [enabled by default]
 shm='*';
    ^
dslab@ds-dx2480-MT:~$ ./a.out
abcdefghijklmnopqrstuvwxyz
dslab@ds-dx2480-MT:~$ 

*/




