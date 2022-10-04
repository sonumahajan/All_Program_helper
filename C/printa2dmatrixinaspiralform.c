
#include<stdio.h>
int main(),spiral();
int main(){
    spiral();
    return 0;
}
int spiral(){
    printf("Enter the size and the elements: ");
    int m,n;
    scanf("%d%d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
    {
        scanf("%d",&arr[i][j]);
    }
    }
    int sr=0,er=m-1,sc=0,ec=n-1;
    while(sr<=er && sc<=ec)
    {
        for(int i=sc;i<=ec;i++)
        printf("%d ", arr[sr][i]);
        sr++;

        for(int i=sr;i<=er;i++)
        printf("%d ", arr[i][ec]);
        ec--;

        if(sr<er)
        {
            for(int i=ec;i>=sc;i--)
            printf("%d ", arr[er][i]);
            er--;
        }
       
        if(sc<ec)
        {
            for(int i=er;i>=sr;i--)
            printf("%d ", arr[i][sc]);
            sc++;
        }
    }
    return 0;
}
