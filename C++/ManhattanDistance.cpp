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
