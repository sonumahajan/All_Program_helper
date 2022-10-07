#include<iostream>
#include<stack>
using namespace std;

int main(){
    //take input string
    string str;
    cin>>str;

    //create a stack
    stack<char> st;

    //push all characters of string into stack
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }

    //pop all characters of stack and print them
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}