#include<stdio.h>
struct point
{
int x;
int y;
}A,B,C,D;
void quad(int i,int j)
{
if(i==0 && j==0)
printf("Point (%d,%d) is on origin\n",i,j);
else
{
if(i>0 &&j>0)
printf("Point (%d,%d) is on First Quad\n",i,j);
if(i<0 &&j>0)
printf("Point (%d,%d) is on Second Quad\n",i,j);
if(i<0 &&j<0)
printf("Point (%d,%d) is on Third Quad\n",i,j);
if(i>0 && j<0)
printf("Point (%d,%d) is on Fourth Quad\n",i,j);
}
}
int main()
{

printf("Enter the co-ordinates of first point=");
scanf("%d%d",&A.x,&A.y);
quad(A.x,A.y);

printf("Enter the co-ordinates of Second point=");
scanf("%d%d",&B.x,&B.y);
quad(B.x,B.y);

printf("Enter the co-ordinates of Third point=");
scanf("%d%d",&C.x,&C.y);
quad(C.x,C.y);

printf("Enter the co-ordinates of Fourth point=");
scanf("%d%d",&D.x,&D.y);
quad(D.x,D.y);


}
