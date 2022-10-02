/*

Problem Link:
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

Time Complexity = O(n)
Space Complexity = O(n)

*/


#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(int i, int j, vector<vector<int> >& M) {
        // i knows j if M[i][j]==1
        if (M[i][j] == 1)
            return true;
        else 
            return false;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        // Push all elements in stack
        for(int i = 0; i < n; i++) {
            s.push(i);
        }
        
        // Until size of stack > 1, check if A knows B or B knows A and push accordingly
        while (s.size() > 1) {
            
            int A = s.top();
            s.pop();
            
            int B = s.top();
            s.pop();
            
            // If A knows B
            if(knows(A, B, M))
                s.push(B);
            
            // If B knows A
            else
                s.push(A);
        }
        
        // Single element in stack is potential candidiate for celebrity
        int ans = s.top();
        
        int countZeroes = 0;
        // Checking in the row of ans 
        for(int i = 0; i < n; i++) {
            if (M[ans][i] == 0)
                countZeroes++;
        }
        
        // If in row, all are not 0's
        if(countZeroes != n) {
            return -1;
        }
        
        int countOnes = 0;
        // Checking in the column of ans
        for(int i = 0; i < n; i++) {
            if (M[i][ans] == 1)
                countOnes++;
        }
        
        // If in column, all are not 1's except diagonal element
        if(countOnes != n-1) {
            return -1;
        }
        
        
        // If comes here, row contains all 0's and column contains all 1's (except diagonal element)
        // So potensial candidate is a celebrity
        return ans;
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}