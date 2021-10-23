#include<stdio.h>
#include<conio.h>
 
void main() {
 
   int cust_no, powerUsage;
   float amount;
 
   printf("Enter the customer number: ");
   scanf("%d", &cust_no);
   printf("Enter the power consumed: ");
   scanf("%d", &powerUsage);
 
   if (powerUsage >= 0 && powerUsage <= 200)
      amount = powerUsage * 0.50;
   else if (powerUsage > 200 && powerUsage < 400)
      amount = 100 + ((powerUsage - 200) * 0.65);
   else if (powerUsage > 400 && powerUsage <= 600)
      amount = 230 + ((powerUsage - 400) * 0.80);
   
   printf("Amount to be paid by customer no. %d is Rs.:%5.2f.", cust_no, amount);
 
   getch();
}
