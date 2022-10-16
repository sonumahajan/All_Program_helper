#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    queue<char> q1;
    for(int i=0; i<s1.length(); i++){
        q1.push(s1[i]);
    }
    queue<char> q2;
    for(int i=0; i<s2.length(); i++){
        q2.push(s2[i]);
    }
    int k=s2.size();
    while(k--){
        char c=q2.front();
        q2.pop();
        q2.push(c);
        
        if(q1==q2){
            cout<<"true";
            break;
        }
    }
    if(q1!=q2) cout<<"false";
    
    return 0;
}
