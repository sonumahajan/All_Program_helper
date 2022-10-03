#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    int n,num,pos;
    char temp[2000];
                int count=0;
                char temp1[2];
    char c[1000];
        char sol[2000]="";
        bool flag = true;
    printf("Enter your choice:\n1 for reading a string\n2 for displaying a string\n3 for merging a string\n4 for copying n characters from mth position\n5 for calculating the length of string\n6 for counting number of words\n7 for counting number of lines\n8 for replacing the input with hello\n0 for exit\n");
    char ch[1000];
    while(flag){
        printf("Enter your choice\n");
    scanf("%d",&n);
    switch (n)
    {
        case 0:
            flag=false;
            break;
    case 1:
        printf("Enter the string and press 9 when you completed entering the string\n");
        scanf("%[^9]%*c",ch);
        break;
    case 2:
        printf("%s",ch);
        break;
    case 3:
        
        printf("Enter the string to merge and press 9 when you completed entering the string\n");
        scanf("%[^9]%*c",c);
        strcat(sol,ch);
        strcat(sol,c);
        printf("%s",sol);
        break;
    case 4:
        printf("Enter the number of characters to be copied\n");
        scanf("%d",&num);
        printf("Enter the position form where you want to copy\n");
        scanf("%d",&pos);
        for(int i =0;i<strlen(ch)-1;i++){
            if(i>=pos && i<=(pos+num))
            {
                printf("%c",ch[i]);
            }
        }
            printf("\n");
            break;
    case 5:
        printf("%ld\n",strlen(ch));
        break;
    case 6:
                
                strcat(ch," ");
        for(int i =0; i<strlen(ch);i++)
        {
            if(ch[i]==' ')
            {
                count++;
                strcpy(temp,"");
            }
            else
            {
                temp1[0]=ch[i];
                strcat(temp,temp1);
                strcpy(temp1,"");
            }
            
        }
        printf("%d\n",count);
        break;
        case 7:
                
                strcat(ch,"\n");
        for(int i =0; i<strlen(ch);i++)
        {
            if(ch[i]=='\n')
            {
                count++;
                strcpy(temp,"");
            }
            else
            {
                temp1[0]=ch[i];
                strcat(temp,temp1);
                strcpy(temp1,"");
            }
            
        }
        printf("%d\n",count-1);
        break;
        case 8:
            strcpy(ch,"hello");
            printf("Your string has been replaced with hello");
            break;
    default:
    printf("Wrong Choice");
        break;
    }}
    return 0;
}
