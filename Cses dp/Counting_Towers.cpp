/*
|_||_|  |_||_|  | || |  | ||_|  |_|| |
|_||_|  | || |  |_||_|  |_||_|  |_||_|
*/

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
#define mex 1000005
ll dp[mex][2];
//0,1-> state when both blocks are attached or detached

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 1;

    f(i, 2, mex)
    {
        dp[i][0] = ((2 % mod) * dp[i - 1][0] % mod + 1 * (dp[i - 1][1] % mod)) % mod;
        dp[i][1] = (1 * dp[i - 1][0] % mod + (4 % mod) * (dp[i - 1][1] % mod)) % mod;
    }

    while (t--)
    {
        ll n;
        cin >> n;

        print((dp[n][1] % mod + dp[n][0] % mod) % mod);
    }
    return 0;
}