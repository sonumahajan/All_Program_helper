//push method
#include <iostream>
#include <queue>
using namespace std;
//two methods 1)make push opearion costly 2)make pop opearion costly
//using method 1
//take 2 queues q1 and q2
//start by adding 1 element in q2
//push that element from q1 to q2
//lastly swap the values of q

//q1
//q2 1
//swap
//q1 1
//q2 
// add new element in q2
//q1  1  //q2 2. push the elements of q1 to q2
//q1    //q2 1 2. Now swap
// q1 1 2 //q2 

class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    Stack(){
        N=0;
    }

    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    
    return 0;
}
