#include<iostream>
using namespace std;

class Tower{
    int count=0;
    public:
    void hanoi(int n,char s,char d,char a) {
        if(n==0) {
            return;
        }
        hanoi(n-1,s,a,d);
        cout<<"Move disc "<<n<<" from "<<s<<" to "<<d<<endl;
        count++;
        hanoi(n-1,a,d,s);
    }
    void moveCount() {
        cout<<"Number of moves : "<<count;
    }
};

int main() {
    int n;
    Tower t;
    cout<<"Enter the number of discs : ";
    cin>>n;
    t.hanoi(n,'A','B','C');
    t.moveCount();
}