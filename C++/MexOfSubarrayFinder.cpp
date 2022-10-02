#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//#define int long long
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rsz resize
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define trav(a,x) for (auto& a: x)
#define MOD 1000000007
#define INF 1e16

void start()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

const int N = 1e5;
int A[N];
int store[N + 1];
int n;
long long k;
set<int> ST;
int solve_mex(int mid) {
	int cnt = 0, l = 0;
	set<int> st = ST;
	for (int i = 0; i <= n; i++)store[i] = 0;
	if (mid != 0 || A[0] != 0) {
		cnt++;
	}
	store[A[0]]++;
	st.erase(A[0]);
	for (int i = 1; i < n; i++) {
		store[A[i]]++;
		st.erase(A[i]);
		while (l < i && *st.begin() > mid) {
			if (--store[A[l]] == 0) {
				st.insert(A[l]);
			}
			l++;
		}
		if (l < i || *st.begin() <= mid) {
			cnt += i - l + 1;
		}
	}
	return cnt >= k;
}
int main() {
	start();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			ST.insert(i);
		}
		ST.insert(n);
		int lo = 0;
		int hi = n;
		int ans = 0;
		while (lo <= hi) {
			int mid = (hi + lo) / 2;
			if (solve_mex(mid)) {
				ans = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}
		ST.clear();
		cout << ans << "\n";
	}
}