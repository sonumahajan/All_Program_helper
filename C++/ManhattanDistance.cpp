/**************************
Given n integer coordinates. The task is to find sum of Manhattan distance between all pairs of coordinates. 
Manhattan Distance between two points (a1, b1) and (a2, b2) is: 
|a1 – a2| + |b1 – b2|

Enter the number of points                                                      
Example 1:
4                                                                               
Enter the X coordinates of the points                                           
1                                                                               
3                                                                               
-1                                                                              
3                                                                               
Enter the Y coordinates of the points                                           
1                                                                               
2                                                                               
8                                                                               
5                                                                               
Result 38

/**********************SOLUTION************************
**************/
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int x[n], y[n], dis=0;
    for(int i=0;i<n;i++){
        scanf("%d", &x[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &y[i]);
    }
    for (int i = 0;i<n;i++){
        for (int j=i+1;j<n;j++){
            dis += (abs(x[i] - x[j]) + abs(y[i] - y[j]));
    }    }            
    
    
    printf("Result %d",dis);
    
    return 0;
    
}
