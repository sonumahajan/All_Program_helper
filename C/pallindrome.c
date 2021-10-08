
#include<stdio.h>
int main()
{
    char str[30],temp;
    int j=0,i=0,mid,flag=0;
    printf("Enter the string to be checked for pallindrome:\n");
    gets(str);
    while(str[j]!='\0')
        j++;
    mid=j/2;
    while(i<mid)
    {
        j--;
        if(str[i]!=str[j])
        {
            flag=1;
            break;
        }
        i++;
    }
    if(flag==0)
        printf("It is a pallindrome.");
    else
        printf("It is not a pallindrome.");
    return 0;

}
