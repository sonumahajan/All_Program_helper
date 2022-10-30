// Tower of hanoi 
#include<stdio.h>
void hanoi(int n, char a, char b, char c){
    if(n!=0){
        hanoi(n-1, a, c, b);
        printf("move disk %d from %c to %c\n", n, a,c);
        hanoi(n-1, b,a,c);
    }
}
void main(){
    int n;
    char a = 'A', b = 'B', c = 'C';
    printf("Enter number of disk : ");
    scanf("%d", &n);
    printf("Solution of Tower of hanoi problem with %d disk : \n");
    printf("Sequence : \n");
    hanoi(n, a, b, c);
    printf("\n");
    return;
}