#include<stdio.h>
int main(){
char ch;
printf("Enter any Character:\n");
scanf("%c",&ch);
if(ch>=65 && ch<=90){
printf("Upper Case Character\n");
}
else if(ch>=97 && ch<=122){
printf("Lower Case Character\n");
}
else if(ch>=48 && ch<=57){
printf("This is a Number\n");
}
else{
printf("Special  Character\n");
}
return 0;
}

