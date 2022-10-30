#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

char s[105];

char* caseConversion () 
{
   
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++)
    {
        scanf("%s", s);

        char* out_ = caseConversion(s);
        printf("%s", out_);
        printf("\n");
    }
}
