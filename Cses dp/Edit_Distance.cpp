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

    string s1, s2;
    cin >> s1 >> s2;

    ll a = s1.size();
    ll b = s2.size();

    ll dp[a + 1][b + 1];

    dp[0][0] = 0;  //when both strings are empty
    f(i, 1, a + 1) //when 2nd string is empty
    {
        dp[i][0] = i;
    }
    f(j, 1, b + 1) //when 1st string is empty
    {
        dp[0][j] = j;
    }

    f(i, 1, a + 1)
    {
        f(j, 1, b + 1)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    print(dp[a][b]);

    return 0;
}