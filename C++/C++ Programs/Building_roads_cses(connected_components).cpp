#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define sz(x) x.size()
#define pb push_back
#define pb2 pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bend(x) x.begin(), x.end()
#define vi vector<ll>
#define mapp map<ll, ll>
#define sett set<ll>
#define ve vector
#define un_m unordered_map<ll, ll>
#define f(i, a, b) for (i = a; i < b; i++)
#define f2(i, a) for (auto i = a.begin(); i != a.end(); i++)
#define MAXN 10000001

#define mp make_pair
#define in(t) scanf("%lld",&t)
#define out(t) printf("%lld",t)

const unsigned int moduli = 1000000007;


ll vis[1000001];
vi v[1000001];
vi l;

void dfs(ll n) {
    vis[n] = 1;
    for (auto a : v[n]) {
        if (!vis[a]) {
            dfs(a);
        }
    }
}

void sol() {
    ll d = 0, ds, e = 0, x, n, k;
    ll i, j, tt = 0, w = 0, t;
    ll ans = 0, cnt = 0, sum = 0;
    ll m;
    cin >> n >> m;
    f(i, 0, m) {
        cin >> d >> e;
        v[d].pb(e);
        v[e].pb(d);
    }
    f(i, 1, n + 1) {
        if (!vis[i])  l.pb(i), dfs(i), ans++;
    }
    cout << ans - 1 << endl;
    cnt = l[0];
    if (ans > 1)
        f(i, 1, ans) {
        ds = l[i];
        cout << cnt << " " << ds << endl;
        cnt = ds;
    }

}

// driver function
int main() {

    ll tc;
    //cin >> tc;
    //while (tc--) {
    sol();
    cout << endl;
    // }

    return 0;
}