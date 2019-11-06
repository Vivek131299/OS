/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104


*****************************Assignment No.7: Inter process communication in Linux using following.
7(a).AIM:- Pipes: Full duplex communication between parent and child processes. Parent process writes a pathname of a file (the contents of the file are desired) on one pipe to be read by child process
and child process writes the contents of the file on second pipe to be read by parent process and
displays on standard output.   *************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(void)
{
int fd1[2],nbytes=1,fd2[2],a=0;
pid_t pid;
char string[80];
char readbuffer[80];
char ch='a',ch1='\n';
FILE *fp;
pipe(fd1);
pipe(fd2);

if((pid=fork())==-1)
{
perror("fork");
exit(1);
}

if(pid==0)
{
close(fd1[1]);
read(fd1[0],readbuffer,sizeof(readbuffer));

printf("filename %s is being read by child process through pipe 1\n\t",readbuffer);
fp=fopen(readbuffer,"r");
//close(fd1[0]);
close(fd2[0]);

printf("\n content of %s are being sent to parent process through pipe2\n\t",readbuffer);
while(a!=-1)
{
a=fscanf(fp,"%c",&ch);
write(fd2[1],&ch,sizeof(ch));
}
close(fd2[1]);
exit(0);
}
else
{
close(fd1[0]);
printf("\n\t In parent process\n");
printf("\n\tEnter name of file::\n\t");
scanf("%s",string);
printf("\n filenames %s is being set by parent process to child process through pipe1\n\t ",string);
write(fd1[1],string,(strlen(string)+1));
wait(NULL);
close(fd1[1]);
close(fd2[1]);
printf("\n content of %s are being received  by parent process through pipe2\n\t ",string);

printf("\n\tIn parent process");
printf("\n\tReceived message");
while(nbytes!=0)
{
printf("%c",ch1);
nbytes=read(fd2[0],&ch1,sizeof(ch1));
}
close(fd2[0]);
}
return(0);
}



/**********************************OUTPUT***************************


/*spllab01@spllab01-vostro:~$ gcc admire.c 
spllab01@spllab01-vostro:~$ ./a.out

	 In parent process

	Enter name of file::
	old.txt

 filenames old.txt is being set by parent process to child process through pipe1
filename old.txt is being read by child process through pipe 1
	
 content of old.txt are being sent to parent process through pipe2
		 
 content of old.txt are being received  by parent process through pipe2
	 
	In parent process
	Received message
*/
