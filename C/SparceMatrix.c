/* Algorithm and code to creat sparce matrix*/

#include<stdio.h>
#include<stdlib.h>
 void print_elements(int r,int c,int **arr)
{ int i,j;
	for(i=0;i<r;i++)
	{
	  for(j=0;j<c;j++)
		 {
		   printf("%d ",arr[i][j]);
		 }
		 printf("\n"); 
	}
}
	
void convert_toSparce(int r,int col,int **a)
{
 int total_row,total_col;
 total_row=r;
	   total_col=col;
	   int i,j,count=0;
	   for(i=0;i<r;i++)
	   {
		 for(j=0;j<col;j++)
		 {
	
		   if(a[i][j]!=0)
		   {
		     count++;
		   }
		 }
	   }
	   
	   printf("Count:%d\n",count);
	   
		int **sparce_arr;
		sparce_arr=(int**)malloc(sizeof(int*)*count+1);
        for(i=0;i<count+1;i++)
		sparce_arr[i]=(int*)malloc(sizeof(int)*3);
	
              sparce_arr[0][0]=total_row;
		      sparce_arr[0][1]=total_col;
		      sparce_arr[0][2]=count;
		 
		int k=1;
		for(i=0;i<total_row;i++)
		{
		  for(j=0;j<total_col;j++)
		  {
		    if(a[i][j]!=0)
		    {
		      sparce_arr[k][0]=i;
		      
		      sparce_arr[k][1]=j;
		      sparce_arr[k][2]=a[i][j];
		      k++;
		    
		    }
		  }
	}

printf("Sparced Matrix:\n");
print_elements(count+1,3,sparce_arr);
}
int main()
	 {
		int row,column;
		printf("Enter the row number :");
		scanf("%d",&row);
		printf("Enter the  coloumn number:");
		scanf("%d",&column);
		int **arr;
		arr=(int**)malloc(sizeof(int*)*row);
		int i,j;
		for(i=0;i<row;i++)
		arr[i]=(int*)malloc(sizeof(int)*column);
		printf("Enter the matix elements\n");
		for(i=0;i<row;i++)
		{
		  for(j=0;j<column;j++)
		  {
		     scanf("%d",&arr[i][j]);
		  }
		}
		print_elements(row,column,arr);
	  convert_toSparce(row,column,arr);
	  free(arr);
	 return 0;
	 
	}

