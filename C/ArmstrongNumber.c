#include <stdio.h>
#include <math.h>
int armstrong(int num)
{
     int ret=0,n=num,digit=0;
     while(n!=0) 
     {
         digit++;
         n=n/10; 
     }
     n=num;
     while(n!=0) 
     {
         ret=ret+ pow(n%10,digit);
         n=n/10; 
     }
     return ret;
}
int main()
{
     printf("Enter a Number\n");
     int n;
     scanf("%d",&n);
     if(n==armstrong(n))
         printf("Armstrong");
     else
         printf("NOT Armstrong");
     return 0;
}
