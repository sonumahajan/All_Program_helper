//Code By- Romijul Laskar
#include<iostream>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<endl
#define out(x) cout << x << endl
class complex{
    int a;
    public:
    void getdata(){
        deb(Enter a :);
        cin>>a;
    }
    void show(){
        deb(The Result is: );
        cout<<a;
    }
    friend complex operator+(complex t,complex t2);
};
complex operator+(complex t,complex t2){
    complex t3;
    t3.a=t.a+t2.a;
    cout<<t3.a;
    return t3;
}
int main()
{
    complex r,u;
    r.getdata();
    u.getdata();
    r+u;
    return 0;
}
