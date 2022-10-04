#include<stdio.h>
int main(){
char ch;
printf("Enter Choices:\n");
scanf("%c",&ch);
if((ch>='A' && ch<='Z') || ( ch>='a' && ch<= 'z'))
{
switch(ch){
case 'A':
case 'E':
case 'I':
case 'O':
case 'U':
case 'a':
case 'e':
case 'i':
case 'o':
case 'u':
printf("%c is Vowel\n",ch);
break;
default:
printf("%c is Consonant\n",ch);
break;
}
}
else{
printf("%c is NOT an Alphabet\n",ch);
}
return 0;
}