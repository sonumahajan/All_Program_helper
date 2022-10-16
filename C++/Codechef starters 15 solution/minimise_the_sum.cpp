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
    ll n;
    cin >> n;
    ll c_n = n;
    vl binaryNum;
    ll i = 0;
    while (n > 0)
    {
        binaryNum.pb(n % 2);
        n = n / 2;
        i++;
    }
    vl v;
    ll c = 1;
    v.pb((1ll << i) - 1);
    for (ll j = i - 2; j >= 0; j--)
    {
        if (binaryNum[j] != binaryNum[j + 1])
        {
            c++;
            v.pb((1ll << j + 1) - 1);
        }
    }
    if (c_n == 0)
    {
        cout << "2" << endl
             << "1 1" << endl;
    }
    else
    {
        cout << c << endl;
        for (ll i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    }
    nl;
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