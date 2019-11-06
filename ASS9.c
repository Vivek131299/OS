/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

************************ASSIGNMENT 9*************************
AIM:-Assignment No. 9: Implement an assignment using File Handling System Calls (Low level system   calls like open, read, write, etc).**/


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main()
{
int fd,ch;
char fname[25];
char buffer[80];
char message[100];
do
{

	printf("1.Create \n 2.Write \n 3.Read \n 4.Exit \n Enter your choice\n ");
	scanf("%d",&ch);
	if(ch==1)
		{
			printf("Enter the file name\n");
			scanf("%s",fname);
			fd=creat(fname,S_IREAD|S_IWRITE);
			if(fd==-1)
				printf("error i opening file  %s\n ",fname);
			else
				printf("file is open for read and write access %s \n ",fname);
		close(fd);
                   }
	if(ch==2)
	{
		printf("Enter the file name\n");
		scanf("%s",fname);
		fd=creat(fname,O_WRONLY);
		if(fd!=-1)
			{
				printf("file is open for write access  %s \n ",fname);
				printf("Enter the DATA\n");
				scanf("%s",message);
				write(fd,message,sizeof(message));
				close(fd);
			}
             }
		if(ch==3)
		{
			printf("Enter the file name");
				scanf("%s",fname);
			fd=creat(fname,O_RDONLY);
		if(fd!=-1)
		{

			printf("file is open for read  access %s \n ",fname);
				if(read(fd,buffer,sizeof(buffer)));
				printf("%s was written to %s \n ",buffer,fname);
		}
		else
printf("error in reading file  %s\n ",fname);


close(fd);
}
}while(ch!=4);
exit(0);
}


/********************************OUTPUT*******************************
/*dslab@ds-dx2480-MT:~$ gcc fantastic.c
dslab@ds-dx2480-MT:~$ ./a.out
1.Create 
 2.Write 
 3.Read 
 4.Exit 
 Enter your choice
 1
Enter the file name
suja
file is open for read and write access suja 
 1.Create 
 2.Write 
 3.Read 
 4.Exit 
 Enter your choice
 2
Enter the file name
suja
file is open for write access  suja 
 Enter the DATA
we are best.
1.Create 
 2.Write 
 3.Read 
 4.Exit 
 Enter your choice
 Enter the file name
file is open for write access  are 
 Enter the DATA
1.Create 
 2.Write 
 3.Read 
 4.Exit 
 Enter your choice
 3
Enter the file namesuja
file is open for read  access suja 
  was written to suja 
 1.Create 
 2.Write 
 3.Read 
 4.Exit 
 Enter your choice
 4
dslab@ds-dx2480-MT:~$ 
*/
