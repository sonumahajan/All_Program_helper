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

    ll n, m;
    cin >> n >> m;

    ll dp[n + 1][m + 1];
    f(i, 0, n + 1)
    {
        f(j, 0, m + 1)
        {
            dp[i][j] = 1e10;
        }
    }

    f(i, 0, n + 1)
    {
        f(j, 0, m + 1)
        {
            if (i == j)
                dp[i][j] = 0;
        }
    }

    f(i, 0, n + 1)
    {
        f(j, 0, m + 1)
        {
            f(k, 0, j)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }

            f(k, 0, i)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }
        }
    }

    print(dp[n][m]);

    return 0;
}