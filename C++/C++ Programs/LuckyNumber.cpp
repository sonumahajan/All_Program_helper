// C++ program for Lucky Numbers
#include <bits/stdc++.h>
using namespace std;
#define bool int

/* Returns 1 if n is a lucky no.
otherwise returns 0*/
bool isLucky(int n)
{
	static int counter = 2;
	
	if(counter > n)
		return 1;
	if(n % counter == 0)
		return 0;
	
	/*calculate next position of input no.
	Variable "next_position" is just for
	readability of the program we can
	remove it and update in "n" only */
	int next_position = n - (n/counter);
	
	counter++;
	return isLucky(next_position);
}

// Driver Code
int main()
{
	int x = 5;
	if( isLucky(x) )
		cout << x << " is a lucky no.";
	else
		cout << x << " is not a lucky no.";
}

// This code is contributed
// by rathbhupendra
