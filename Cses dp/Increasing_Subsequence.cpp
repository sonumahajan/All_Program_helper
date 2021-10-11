#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define pb push_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define endl '\n'
#define F first
#define S second
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define to(n) to_string(n)
#define low(v, n) lower_bound(v.begin(), v.end(), n) - v.begin()
#define upp(v, n) upper_bound(v.begin(), v.end(), n) - v.begin()
#define mod 1000000007
#define mex 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll A[n];
    f(i, 0, n)
    {
        cin >> A[i];
    }
    //O(nlogn)
    vl v;
    f(i, 0, n)
    {
        if (v.size() == 0)
        {
            v.pb(A[i]);
            continue;
        }
        if (A[i] > v[v.size() - 1])
        {
            v.pb(A[i]);
            continue;
        }

        ll next_greater = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        v[next_greater] = A[i];
    }
    print(v.size());
    return 0;
}