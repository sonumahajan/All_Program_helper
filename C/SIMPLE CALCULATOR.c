#include<stdio.h>
int main()
{
int choice=0;	
int a=0,b=0,c=0;
printf("\n SIMPLE CALCULATOR:");
target : scanf("%d",&choice);
switch(choice)
{
	case 1:
		printf("\n 1. ADDITION:");
		scanf("%d",&a);
		scanf("%d",&b);
		c=a+b;
		printf("%d",c);
		break;
    case 2:
    	printf("\n 2. SUBSTRACTION:");
    	scanf("%d",&a);
		scanf("%d",&b);
		c=a-b;
		printf("%d",c);
    	break;
    case 3:
		printf("\n 3. MULTIPLICATION:");
    	scanf("%d",&a);
		scanf("%d",&b);
		c=a*b;
		printf("%d",c);
    	break;
    case 4:
		printf("\n 4.DIVITION:");
    	scanf("%d",&a);
		scanf("%d",&b);
		c=a/b;
		printf("%d",c);
    	break;
    case 5:
		printf("\n 5. MODULERS:");
    	scanf("%d",&a);
		scanf("%d",&b);
		c=a%b;
		printf("%d",c);
    	break;
    case 6:
		printf("\n 6. SQUARE:");
    	scanf("%d",&a);
		c=a*a;
		printf("%d",c);
    	break;
    case 7:
		printf("\n 7. CUBE:");
    	scanf("%d",&b);
		c=b*b*b;
		printf("%d",c);
    	break;
    default:
    	printf("\n ENTER CHOICE (1-7):");
    	goto target;
    	break;
}
return 0;
}
