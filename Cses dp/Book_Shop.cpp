#include <bits/stdc++.h>
using namespace std;

#define ll int
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

ll book(ll s, ll n, ll price[], ll page[])
{
    ll dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));

    f(i, 1, n + 1)
    {
        f(j, 1, s + 1)
        {
            if (price[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i - 1]] + page[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x;
    cin >> n >> x;
    ll price[n], page[n];
    f(i, 0, n)
    {
        cin >> price[i];
    }
    f(i, 0, n)
    {
        cin >> page[i];
    }

    print(book(x, n, price, page));

    return 0;
}
