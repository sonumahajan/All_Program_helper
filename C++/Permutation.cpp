#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define ll long long
#define fi(i,m,n) for(int i=m;i<n;i++)
#define test int tt;cin>>tt;while(tt-->0)
#define vll vector<ll>
#define mll map<ll,ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define str string
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define end cout<<endl;
#define sort(v) sort(v.begin(),v.end());
#define count(v,x) count(v.begin(),v.end(),x);
#define vstr vector<string>
using namespace std;

vector<vector<ll>>ans;
void permutation(vll &v, int idx) {
	if (idx == v.size()) {
		ans.pb(v);
		return;
	}

	fi(i, idx, v.size()) {
		swap(v[i], v[idx]);
		permutation(v, idx + 1);
		swap(v[i], v[idx]);
	}
}

int main()
{
	int n;
	cin >> n;
	vll v(n);
	fi(i, 0, n) {
		cin >> v[i];
	}

	// This is also a stl method for generate permutation
	// sort(all(v));
	// do {
	// 	ans.pb(v);
	// } while (next_permutation(all(v)));

	permutation(v, 0);
	for (auto v : ans) {
		for (auto v1 : v) {
			cout << v1 << " ";
		}
		end
	}
	return 0;
}