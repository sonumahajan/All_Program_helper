#include<stdio.h>
#include<conio.h>

int main(){
    printf("Press 1 for addition.\nPress 2 for subtraction.\nPress 3 for multiplication.\nPress 4 for division.\n");
    int choice;
    scanf("%d",&choice);
    int a,b;
    printf("\nEnter the value of a:\n");
    scanf("%d",&a);
    printf("\nEnter the value of b:\n");
    scanf("%d",&b);
    switch (choice){
        case 1:
            printf("\nTHE SUM IS:%d",a+b);
            break;
        case 2:
            printf("\nTHE DIFFERENCE IS:%d",a-b);
            break;
        case 3:
            printf("\nTHE PRODUCT IS:%d",a*b);
            break;
        case 4:
            printf("\nTHE QUOTIENT IS:%d",a/b);
            break;
        default:
            printf("Error");
            break;
    }
}