#define M 1000000007

int power(int x,int y)
{
    int res=1;
    
    while(y>0)
    {
       if(y&1)
       res=((res%M)*(x%M))%M;
       
       y=y>>1;
       x=((x%M)*(x%M))%M;
    }
    re res;
}  
