#include<iostream>
using namespace std;
class Matrix
{
 int a[3][3];
 public:
   int& operator() (int i,int j)
   {
     return(a[i][j]);
   }
   void showmatrix()
   {
    int i,j;
    for(i=0;i<3;i++)
    {
      for(j=0;j<3;j++)
        cout<<a[i][j]<<" ";
      cout<<endl;
    }

   }
};
int main()
{
 Matrix m;
   m(0,0)=5;
   m(0,1)=5;
   m(0,2)=5;
   m(1,0)=7;
   m(1,1)=7;
   m(1,2)=7;
   m(2,0)=9;
   m(2,1)=9;
   m(2,2)=9;
   m.showmatrix();
   return 0;
}
