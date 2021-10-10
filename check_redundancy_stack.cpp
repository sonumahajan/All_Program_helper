#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool checkforredundancy(string &input)
{
    //create a stack
    stack<char> s;
    int count =0; //initialise counter variable

    //scan till the end of expression
    for(int i=0;i<input.length();i++)
    {
        if(input[i]!=')')
          s.push(input[i]);
        if(input[i]==')' && s.size()!=0 )
        {
            count=0;
            while(s.size()!=0 && s.top()!='(')
            {
                s.pop();
                ++count;
            }
            s.pop();

            if(count==0)
            {
                return true;
            }
            // else{
            //     s.pop();
            // }
            
        }
        
        
    }
    // while(s.size()!=0)
    //   {
    //       cout<<s.top()<<" ";
    //       s.pop();
    //   }
    if(count==0)
      return true;
    else 
      return false;
}


int main()
{
    //input expression
    string input = "()";
    //checkforredundancy(input);
    if(checkforredundancy(input))
       cout<<"Redundant"<<endl;
    else{
        cout<<"not redundant"<<endl;
    }
}