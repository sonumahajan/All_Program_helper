// Program to implement QuickSort in C language.
// Time Complexity -- O(nlogn)
#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quicksort(int arr[],int low ,int high)
{
    if(low<high)
    {
        int pos=partition(arr,low,high);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }
}
int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int i=start,j=end;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j],&arr[start]);
    return j;
}
void show(int arr[],int n)
{
    printf("\n Array Elements: ");
    for(int i=0;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;
    printf("Enter No. of Elements :");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("ARRAY :");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
