#include<stdio.h>
#include<math.h>
int main(){
    int p,t;
    float c,s,r,a;
    printf("Enter The Principal :");
    scanf("%d",&p);
    printf("\n Enter The Rate of Interest:");
    scanf("%f",&r);
    printf("\n Enter the Time:");
    scanf("%d",&t);
    s=p*(1+r*t);
    printf("\n The Total amount after Simple Interest is=%.2f",s);
    a=(1+(r/100));
    c=p*pow(a,t);
   printf("\n The Total amount after Compound Interest is=%.2f",c);
   return 0;
}
