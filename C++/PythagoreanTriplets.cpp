#include <iostream>
using namespace std;

void pythagoreanTriplets(int limit)
{
    int a, b, c=0;
    int m=2;
    
    while(c<limit)
    {
        for(int n=1; n<m; n++)
        {
            a=m*m-n*n;
            b=2*m*n;
            c=m*m+n*n;
            
            if(c>limit)
            break;
            
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        m++;
    }
}

int main()
{
    int limit;
    cin>>limit;
    pythagoreanTriplets(limit);
}