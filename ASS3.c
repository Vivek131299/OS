/*NAME :Vivek Bhavsar
ROLL NO.:TEIT104

******************************ASSIGNMENT NO-3*****************************
AIM:-Implement multithreading for Matrix Multiplication using pthreads.

*/

#include <stdio.h>
#include <pthread.h>
void *multiplication (void *p);
int m, n, p, q, c, d, k,sum=0;
int first[10][10], second[10][10], multiply[10][10];
 int main()
{

pthread_t ta[5];
printf("enter the rows and columns in first matrix");
scanf("%d%d",&m,&n);
printf("Enter elements in first matrix");
for(c=0;c<m;c++)
for(d=0;d<n;d++)
scanf("%d",&first[c][d]);

printf("enter the rows and columns in second matrix");
scanf("%d%d",&p,&q); 
printf("Enter elements in second matrix");
for(c=0;c<p;c++)
for(d=0;d<q;d++)
scanf("%d",&second[c][d]);

if (n != p)
    printf("The matrices can't be multiplied with each other.\n");
  else
  {
for(c=0;c<m;c++)
{

pthread_create( &ta[c], NULL, multiplication, (void*)c);
}
for(c=0;c<m;c++)
{

pthread_join(ta[c], NULL);
}

printf("Product of the matrices:\n");
 for (c = 0; c < m; c++) 
{
 for (d = 0; d < q; d++)
printf("%d\t", multiply[c][d]);
printf("\n");
}
}
return 0;
}


void *multiplication (void *z)
{

int c;
c=(long) z;
{
for(d=0;d<q;d++)
{
for(k=0;k<m;k++)
{
printf("thread no %ld ",c);
 sum =sum+first[c][k]*second[k][d];
}
 multiply[c][d] = sum;
sum =0;
 }
}

}
 
/************************OUTPUT********************************************
spllab01@spllab01-Vostro-3268:~$ gcc mul.c -o mul -lpthread
mul.c: In function �main�:
mul.c:31:47: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
 pthread_create( &ta[c], NULL, multiplication, (void*)c);
                                               ^
mul.c: In function �multiplication�:
mul.c:61:21: warning: format �%ld� expects argument of type �long int�, but argument 2 has type �int� [-Wformat=]
 printf("thread no %ld ",c);
                   ~~^
                   %d
spllab01@spllab01-Vostro-3268:~$ ./mul
enter the rows and columns in first matrix2
2
Enter elements in first matrix2
2
4
4
enter the rows and columns in second matrix2
2
Enter elements in second matrix3
3
1
1
thread no 0 thread no 0 thread no 0 thread no 0 thread no 1 thread no 1 thread no 1 thread no 1 Product of the matrices:
8	8	
16	16	
spllab01@spllab01-Vostro-3268:~$ 
*/
