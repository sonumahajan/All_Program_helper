//Merging the array and printing it.
#include<stdio.h>
int main()
{
    int u1,u2;
    printf("Enter no. of elements for the first array:\n");
    scanf("%d",&u1);
    printf("Enter no. of elements for the second array:\n");
    scanf("%d",&u2);
    int a1merge[u1],a2merge[u2],mergedarray[u1+u2],i;
    printf("Enter the elements to the first array:\n");
    for (i=0;i<u1;i++)
    scanf("%d",&a1merge[i]);
    printf("Displaying the first array data...\n");
    for(i=0;i<u1;i++)
    printf("%d ",a1merge[i]);
    printf("\nEnter the elements to the second array:\n");
    for (i=0;i<u2;i++)
    scanf("%d",&a2merge[i]);
    printf("Displaying the second array data...\n");
    for(i=0;i<u2;i++)
    printf("%d ",a2merge[i]);
    // Logic
    for(i=0;i<u1;i++)
    mergedarray[i]=a1merge[i];
    for(i=u1;i<(u1+u2);i++)
    mergedarray[i]=a2merge[i-u1];
    printf("\nDisplaying the merged array data...\n");
    for(i=0;i<(u1+u2);i++)
    printf("%d ",mergedarray[i]);
    return 0;
}