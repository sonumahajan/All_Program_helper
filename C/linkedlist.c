#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cout<<"Enter Row and Column- ";
    cin>>r>>c;
    int m[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "enter " << i << "x" << j << " element - ";
            cin >> m[i][j];
        }
    }
    cout<<"Displaying Matrix: -\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter Row and Column To find; ";
    cin>>r>>c;
    cout<<"The Element  is- "<<m[r-1][c-1];
    return 0;
}
