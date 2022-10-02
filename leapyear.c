#include<stdio.h>
int main(){
int year;
printf("Enter a year:\n");
scanf("%d",&year);
if(year%4==0&&year%100!=0||year%400==0){
printf("%d is a leap year!",year);
}
else{
printf("%d is NOT a leap year!",year);
}
return 0;
}

