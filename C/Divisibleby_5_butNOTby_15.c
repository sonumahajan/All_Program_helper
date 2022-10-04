
#include<stdio.h>
int main(){
int num;
printf("Enter any number:\n");
scanf("%d",&num);
if(num%5==0){
if(num%15==0){
printf("%d is divisible by 15!",num);
}
else
{
printf("%d is divisible by 5 but NOT by 15!",num);
}
}
else
{
printf("%d is NOT divisible by 5!",num);
}
return 0;
}
