#include<stdio.h>
int pascal(),binomial(int line,int element),fact(int a);
int main(){
    return pascal();
}
int pascal(){
    printf("Enter the number of rows: ");
    int line;
    scanf("%d",&line);
    int cntr=1;
    for(int i=1;i<=line;i++,cntr+=2);
    cntr-=2;
    for(int i=0;i<line;i++)
    {
        int whitespace=0;
        for(int j=1,k=0;j<=cntr;j++)
        {
            if(j<=((cntr-(2*i+1))/2) || j>((cntr-(2*i+1))/2)+(2*i+1) || whitespace)
            {
                printf(" ");
                whitespace=0;
            }
            else
            {
                printf("%d",binomial(i, k));
                k++;
                whitespace=1;
            }
            
        }
        printf("\n");
    }
    return 0;
}
int binomial(int line, int element)
{
    int res= (fact(line)/(fact(element)*fact(line-element)));
    return res;
}
int fact(int a){
    if(a==1 || a==0)
    return 1;
    else
    return a*fact(a-1);
	};
