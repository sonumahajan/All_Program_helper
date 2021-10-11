#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define vpl vector<pair<ll, ll>>
#define mll map<ll, ll>
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define ct(x) cout << x << " "
#define endl '\n'
#define F first
#define S second
#define gcd __gcd
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define to(n) to_string(n)
#define mod 1000000007
#define mex 100005
ll A[5001];
ll dp[5001][5001];

ll solve(ll a, ll b)
{
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    if (a > b)
    {
        dp[a][b] = 0;
        return 0;
    }

    ll k1 = A[a] + min(solve(a + 1, b - 1), solve(a + 2, b));
    ll k2 = A[b] + min(solve(a + 1, b - 1), solve(a, b - 2));
    dp[a][b] = max(k1, k2);
    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    ll n;
    cin >> n;

    f(i, 0, n)
    {
        cin >> A[i];
    }
    solve(0, n - 1);
    print(solve(0, n - 1));
    return 0;
}