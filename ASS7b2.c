/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104


*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define FIFO_NAME1 "comm_pipe1"
#define FIFO_NAME2 "comm_pipe2"

int main()
{
char s1[300],s2[300];
int num,fd1,fd2,byt;
//printf("producer");
mknod(FIFO_NAME1,S_IFIFO | 0666,0);
mknod(FIFO_NAME2,S_IFIFO | 0666,0);

printf("waiting for consumer..\n");
fd1=open(FIFO_NAME1, O_WRONLY);
fd2=open(FIFO_NAME2, O_RDONLY);

printf("got a consumer --type some stuff\n");
fgets( s1,20, stdin );
//gets(s1);
//printf("enter");
//scanf("%s",s1);
if((num=write(fd1,s1,strlen(s1)))==-1)
perror("write");
else
{
printf("Speak:wrote %d bytes to file 1\n",num);
byt=read(fd2,s2,300);
s2[byt]='\0';
printf("%s\n",s2);
}
return 0;
}

/**************************OUTPUT*************************
spllab01@spllab01-vostro:~$ gcc fast.c 
spllab01@spllab01-vostro:~$ ./a.out
waiting for consumer..
got a consumer --type some stuff
 iam shruti.    
Speak:wrote 13 bytes to file 1
for the given sentence the word count is 3
 vowel cnt is 5
 character count is 11
 linear are 0
spllab01@spllab01-vostro:~$ 
*/
