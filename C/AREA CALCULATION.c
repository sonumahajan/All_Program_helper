#include<stdio.h>
int main()
{
	int choice = 0;
	float area= 0,a=0,b=0;
	printf("\n SHAPE MENU:");
	printf("\n 1. CIRCLE CALCULATION:");
	printf("\n 2. SQUARE CALCULATION:");
	printf("\n 3. RECTANGLE CALCULATION:");
	printf("\n 4. TRIANGLE CALCULATION:");
	printf("\n    CHOICE NO (1-4):");
	scanf ("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("\n 1.CIRCLE CALCULATION:");
			scanf("%f",&a);
			area = 3.14f*a*a;
			printf("\n Area Is %.2f",area);
			break;
		case 2:
		    printf("\n 2.SQUARE CALCULATION:");
			scanf("%f",&a);
			area = a*a;
			printf("\n Area Is %.2f",area);
			break;
		case 3:
			printf("\n 3.RECTANGLE CALCULATION:");
			scanf("%f",&a);
			scanf("%f",&b);
			area = a*b;
			printf("\n Area Is %f",area);
			break;
		case 4:
			printf("\n 4.TRIANGLE CALCULATION:");
			scanf("%f",&a);
			scanf("%f",&b);
			area = 0.5f*a*b;
			printf("\n Area Is %.2f",area);
			break;
		default:
			printf("\n ENTER CHOICE IN BETWEEN(1-4):");
			break;
	}
	return 0;
}
