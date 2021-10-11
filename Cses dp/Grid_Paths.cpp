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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    char A[n][n];
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cin >> A[i][j];
        }
    }

    ll dp[n][n];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            if (A[i][j] == '*')
            {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    print(dp[n - 1][n - 1]);

    return 0;
}