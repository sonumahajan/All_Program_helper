/* Program to find duplicates in an unsorted array
for e.g. 1 3 2 2 1 
output : 
1 repeated 2 times
2 repeated 2 times

TIME COMPLEXITY : O(n^2)
*/

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
using namespace std;

void count_dup(int a[], int n)
{
    int count;                  //to store count of repeated value
    for (int i = 0; i < n; i++) //iterate through beginning to end
    {
        count = 1;      //set count to 1
        if (a[i] != -1) // if element is not visited
        {
            for (int j = i + 1; j < n; j++) //start loop from i+1
            {
                if (a[i] == a[j]) //if two elements are same
                {
                    count++;   //increase count
                    a[j] = -1; //set element to -1 (or visited)
                }
            }
        }

        if (count > 1)
        {
            cout << "\nElement " << a[i] << " Repeated : " << count; //Show the element and repeated value
        }
    }
}

int main()
{
    int a[20];
    int s;
    cout << "\nEnter Size of Array :"; //take input from user
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
    }

    count_dup(a, s);
}
