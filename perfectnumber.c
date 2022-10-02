#include<stdio.h>
int isPerfect();
void main(){
    printf("Enter a number: ");
    int n;
    scanf("%d",&n);
    if(n!=1 && isPerfect(n)==n)
    printf("It is a perfect number");
    else
    printf("It is not a perfect number");
}
int isPerfect(int n){
    int sum=1;
    for(int i=2;i<=(int)n/2;i++)
    {
        if(n%i==0)
        sum+=i;
    }
    return sum;
}
