#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    //two stacks are used
    //one stores the data in lifo model
    //another one starts storing elements of s1
    //when pop function is used on queue, elements of s2 are displayed

    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        if(s2.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    
    return 0;
}
