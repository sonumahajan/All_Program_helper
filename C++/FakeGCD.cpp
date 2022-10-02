// This is the link to the problem : https://www.codechef.com/COOK133C/problems/FAKEGCD
// Below is my solution
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int k=1;

        for(int i=0; i<n; i++)
        {
            cout << k << " ";
            k++;
        }

        cout << endl;
    }
    return 0;
}
