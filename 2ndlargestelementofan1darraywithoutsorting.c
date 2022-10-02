#include<stdio.h>
int main()
{
  int a[10], Size, i, Largest, Position,SecondLargest;
  printf("\nPlease Enter the size of an array \n");
  scanf("%d",&Size);
  printf("\nPlease Enter %d elements of an array: \n", Size);
  for(i=0; i<Size; i++)
   {
     scanf("%d",&a[i]);
   }   
   Largest = a[0];
   SecondLargest = a[0];
  for(i=1; i<Size; i++)
   {
    if(Largest<a[i])
     {
     	SecondLargest = Largest;
        Largest=a[i];
     }   
    else if( a[i]>SecondLargest && a[i]<Largest  )
	 {
     	SecondLargest=a[i];
     	Position = i;
     }
   }
  printf("\nSecondLargest element in an Array = %d", SecondLargest);
  printf("\nIndex position of the SecondLargest element = %d", Position);
  return 0;
}
