/***********************ASSIGNMENT NO 02

Aim: Process control system calls: The demonstration of FORK, EXECVE and WAIT system calls along with
zombie and orphan states.
B. Implement the C program in which main program accepts an integer array. Main program uses the
FORK system call to create a new process called a child process. Parent process sorts an integer array
and passes the sorted array to child process through the command line arguments of EXECVE system
call. The child process uses EXECVE system call to load new program that uses this sorted array for
performing the binary search to search the particular item in the array.
Main program*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int val[10],ele;
int n,i,j;
char *cval[10];
pid_t pid;
char *newe[]={NULL};
printf("Enter size of Array");
scanf("%d",&n);
printf("\nEnter Array");
for(i=0;i<n;i++)
{
scanf("%d",&val[i]);
}
printf("\nEntered Array is");
for(i=0;i<n;i++)
{
printf("\t%d",val[i]);
}
for(i=1;i<n;i++)
{ for(j=0;j<n-1;j++) {
if(val[j]>val[j+1])
{
int temp=val[j];
val[j]=val[j+1];
val[j+1]=temp;
} } }
printf("\nSorted Array is");
for(i=0;i<n;i++)
{
printf("\t%d",val[i]);
}
printf("\nEnter Element to search");
scanf("%d",&ele);
val[i]=ele;
for(i=0;i<n+1;i++)
{
char a[sizeof(int)];
snprintf(a,sizeof(int),"%d",val[i]);
cval[i]=malloc(sizeof(a));
strcpy(cval[i],a);

ASSIGNMENT NO 02

}
cval[i]=NULL;
pid=fork();
if(pid==0)
{
execve("./p2b",cval,newe);
perror("error");
}
}
Child program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[],char *en[])
{
int i,j,mid,ele;
int arr[argc];
for(j=0;j<argc-1;j++)
{
int n=atoi(argv[j]);
arr[j]=n;
}
ele=atoi(argv[j]);
i = 0;
j= argc - 1;
mid = (i+j)/2;
while (arr[mid]!=ele && i<=j)
{
if (ele>arr[mid])
i = mid + 1;
else
j=mid-1;
mid = (i+j)/2;
}
if(i<=j)
printf("Element is present in the list");
else
printf("not found!" );
}
/* *******************************************OUTPUT**************************************************
spllab01@spllab01-vostro:~$ gcc p2b.c -o p2b
spllab01@spllab01-vostro:~$ ./p2b
Element is present in the listspllab01@spllab01-vostro:~$ gcc p2a.c -o p2a
spllab01@spllab01-vostro:~$ ./p2a
Enter size of Array4
Enter Array2
1
6
4
Entered Array is 2 1 6 4
Sorted Array is 1 2 4 6
Enter Element to search4
spllab01@spllab01-vostro:~$ Element is present in the list*/
