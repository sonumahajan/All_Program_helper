// C++ implementation to convert a binary number
// to octal number
#include <bits/stdc++.h>
using namespace std;

// function to create map between binary
// number and its equivalent octal
void createMap(unordered_map<string, char> *um)
{
	(*um)["000"] = '0';
	(*um)["001"] = '1';
	(*um)["010"] = '2';
	(*um)["011"] = '3';
	(*um)["100"] = '4';
	(*um)["101"] = '5';
	(*um)["110"] = '6';
	(*um)["111"] = '7';
}

// Function to find octal equivalent of binary
string convertBinToOct(string bin)
{
	int l = bin.size();
	int t = bin.find_first_of('.');
	
	// length of string before '.'
	int len_left = t != -1 ? t : l;
	
	// add min 0's in the beginning to make
	// left substring length divisible by 3
	for (int i = 1; i <= (3 - len_left % 3) % 3; i++)
		bin = '0' + bin;
	
	// if decimal point exists
	if (t != -1)
	{
		// length of string after '.'
		int len_right = l - len_left - 1;
		
		// add min 0's in the end to make right
		// substring length divisible by 3
		for (int i = 1; i <= (3 - len_right % 3) % 3; i++)
			bin = bin + '0';
	}
	
	// create map between binary and its
	// equivalent octal code
	unordered_map<string, char> bin_oct_map;
	createMap(&bin_oct_map);
	
	int i = 0;
	string octal = "";
	
	while (1)
	{
		// one by one extract from left, substring
		// of size 3 and add its octal code
		octal += bin_oct_map[bin.substr(i, 3)];
		i += 3;
		if (i == bin.size())
			break;
			
		// if '.' is encountered add it to result
		if (bin.at(i) == '.')
		{
			octal += '.';
			i++;
		}
	}
	
	// required octal number
	return octal;
}

// Driver program to test above
int main()
{
	string bin = "1111001010010100001.010110110011011";
	cout << "Octal number = "
		<< convertBinToOct(bin);
	return 0;	
}
