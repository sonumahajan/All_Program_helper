#include<stdio.h>
int main();
int det(int arr[100][100],int size);
int main(){
    printf("Enter the size and elements: ");
    int n;
    scanf("%d",&n);
    int arr[100][100];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&arr[i][j]);
    printf("%d",det(arr,n));
}
int det(int arr[100][100],int size){
    int determinant=0;
    int o=1;
    int arr_new[100][100];
    int tempr=0,tempc=0;
    if(size==2)
    {
        determinant= (arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1]);
        return determinant;
    }
    else
    {
        for(int i = 0 ; i < size ; i++)
        {
            int tempr = 0, tempc = 0;
            for(int j = 0 ; j < size ; j++)
            {
                for(int k = 0 ; k < size; k++)
                {
                    if(j != 0 && k != i)
                    {
                        arr_new[tempr][tempc++] = arr[j][k];
                        if(tempc>size-2)
                        {
                            tempr++;
                            tempc=0;
                        }
                    }
                }
            }
            determinant = determinant + o*(arr[0][i]*det(arr_new,size-1));
            o=-1*o;
        }
    }
    printf("The determinant of matrix is: %d\n\n", determinant);
return determinant;
}
