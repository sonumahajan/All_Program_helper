 #include <bits/stdc++.h>
using namespace std;
//-------------------------------------------------------------------------------------------------
#define ll long long
#define nl cout << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vl vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define msl map<string, ll>
#define mls map<ll, string>
#define umll unordered_map<ll, ll>
#define umsl unordered_map<string, ll>
#define umls unordered_map<ll, string>
#define sl set<ll>
#define ss set<string>
#define usl unordered_set<ll>
#define uss unordered_set<string>
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define sizear(arr) sizeof(arr) / sizeof(arr[0]);
#define fo(i, a, n) for (ll i = a; i < n; i++)
//-------------------------------------------------------------------------------------------------
void solution()
{
    ll n, a, b, even = 0, odd = 0;
    cin >> n >> a >> b;
    while (n % 2 == 0)
    {
        even++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            odd++;
            n = n / i;
        }
    }
    if (n > 2)
        odd++;

    if (a >= 0 && b >= 0)
        cout << a * even + b * odd << endl;
    else if (a < 0 && b >= 0)
        cout << ((even > 0) ? a : 0) + b * odd << endl;
    else if (a >= 0 && b < 0)
        cout << ((even > 0) ? a * even : b) << endl;
    else
    {
        if (even > 0)
            cout << a << endl;
        else
            cout << b << endl;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }

    return 0;
}