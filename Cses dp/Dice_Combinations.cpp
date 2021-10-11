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
vl dice(mex, 0);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dice[1] = 1;
    f(i, 2, 7)
    {
        dice[i] = 2 * dice[i - 1];
    }

    f(i, 7, mex)
    {
        dice[i] = (dice[i - 1] % mod + dice[i - 2] % mod + dice[i - 3] % mod + dice[i - 4] % mod + dice[i - 5] % mod + dice[i - 6] % mod) % mod;
    }

    ll n;
    cin >> n;
    print(dice[n]);

    return 0;
}