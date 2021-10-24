#include<stdio.h>
#define max 50

void InsertionSort(int arr[],int n){
	int i,j,key;
	for(j=2;j<=n;j++){
		key=arr[j];
		i=j-1;
		while(i>0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i=i-1;
			
		}
		arr[i+1]=key;
	}
	
}
int main(){
	int arr[max],i,n;
	
	printf("Enter the no. of elements in the array:");
	scanf("%d",&n);
	printf("Elements are:\n");
	for(i=1;i<=n;++i)
	{
     scanf("%d",&arr[i]);
	}
	
	InsertionSort(arr,n);
	printf("The sorted elements are:\n");
	for(i=1;i<=n;i++)
	{
     printf("%d\t",arr[i]);
	}
	
	return 0;
}