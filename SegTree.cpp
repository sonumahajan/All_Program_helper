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
#define maxxx 100000000
#define mp make_pair
#define in(t) scanf("%lld",&t)
#define out(t) printf("%lld",t)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PQ priority_queue
#define ts(s) to_string(s)

const unsigned int moduli = 1000000007;
ll a[100001],st[400004];


void build(ll si, ll ss, ll se){
	if(se==ss) 
	{
		st[si]=a[ss];
		return;
	}
	
	ll mid=(se+ss)/2;
	build(2*si,ss,mid);
	build(2*si+1,mid+1,se);
	st[si]=min(st[2*si],st[2*si+1]);
}
ll qu(ll si, ll ss, ll se, ll qs, ll qe){
	if(qe<ss || qs>se) return maxxx;
	if(qs<=ss && qe>=se) return st[si];
	ll mid = (ss+se)/2;
	ll l = qu(2*si,ss,mid,qs,qe);
	ll r = qu(2*si+1,mid+1,se,qs,qe);	
	return min(l,r);
}
void sol() {
    ll d=0,ds,e=0,x,n,k;
    ll i,j,tt=0,w=0,t,y;
    ll cnt=0,ans=0,sum=0;
    cin>>n;
    f(i,1,n+1){
    	cin>>a[i];
	}
	build(1,1,n);
	cin>>k;
	while(k--){
		cin>>w>>d>>e;
		if(w==0){
			update(1,1,n,d,e);
		}
		else
		cout<<qu(1,1,n,d,e)<<endl;
	}
}

// driver function
int main() {
    fast_io;
    ll tc=1; //cin >> tc; 
    while (tc--) {
        sol();
        //cout << endl;
    }

   return 0;
}
