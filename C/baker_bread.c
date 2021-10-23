/*A baker wants to raise some yeast in a container for making bread.
Initially, the container is empty. Each morning, the baker can put any number of yeast into the container. And each night, every yeast cell in the container will split into two yeast cells. You hope to see exactly x yeast cells in the container at some moment.
What is the minimum number of yeast cells the baker needs to put into the container across those days?

Input Description:
t=> no of test cases
x=> no of yeast cells the baker wants

Output Description:
print minimum number of yeast cells the baker has to add.

Constraints:
1<=t<=1000
1<=x<=10^6

Example:

Input:
2
5
8

Output:
2
1

Expalination:
For the first case, the baker can add one yeast cell in the container in the first day morning and at the third morning there will be 4 yeast cells in the box. Now we put one more resulting 5 in the container. We added 2 yeast cells in the process so the answer is 2.

For the second case, we can put one in the first morning and in the 4-th morning there will be 8 in the container. So the answer is 1. */
#include<stdio.h>
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&x);
        if(x%2==0)
        {
            printf("1");
        }
        else
        printf("2");
    }
}