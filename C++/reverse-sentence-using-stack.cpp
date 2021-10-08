#include <bits/stdc++.h>
#define ll long long
#define HARE std::ios::sync_with_stdio(false);
#define KRISHNA cin.tie(NULL);cout.tie(NULL);
#define test ll tt;cin>>tt;while(tt-->0)
#define all(c) c.begin(),c.end()
using namespace std;

void reverseString(string s) {
	stack<string>st;
	for (int i = 0; i < s.length(); i++) {
		string word = "";
		while (s[i] != ' ' && i != s.length()) {
			word += s[i];
			i++;
		}
		st.push(word);
	}
	while (!(st.empty())) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main()
{
	HARE KRISHNA
	//test
	string s = "Hey, how are you doing?";
	reverseString(s);

	return 0;
}