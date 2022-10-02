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
#define maxxx INT32_MAX
#define mp make_pair
#define in(t) scanf("%lld",&t)
#define out(t) printf("%lld",t)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PQ priority_queue
#define ts(s) to_string(s)
/*
    stringstream geek(str);
    nn=0;
    geek>>nn;

   #define ll int
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
   #define maxxx INT32_MAX
   #define mp make_pair
   #define in(t) scanf("%lld",&t)
   #define out(t) printf("%lld",t)
   #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
   #define PQ priority_queue
   #define ts(s) to_string(s)
   const unsigned int mod = 1000000007;
   
    bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
    { 
        return (a.second < b.second); 
    } 
    sort(vect.begin(), vect.end(), sortbysec);  
    
    ll d=0,ds,e=0,x,n,k;
    ll i,j,tt=0,w=0,t,y;
    ll cnt=0,ans=0,sum=0; 

    stringstream geek(str);
    ll nn=0;
    geek>>nn;

    
*/
const unsigned int moduli = 1000000007;

ll fr[1000001],s[1000001],e[1000001];
void sol() {
    ll d=0,ds,x,n,k;
    ll i,j,w=0,t,y;
    ll cnt=0,ans=0,sum=0;
    string ss;
    cin>>ss;
    stack<ll> st;
    n=sz(ss);
	
	fr[0]=1;
	
    f(i,0,n){
    	if(ss[i]=='(') st.push(i);
		else{
			if(!st.empty()) 
			{
				ll tt=st.top();
				st.pop();
				s[i]=e[i]=tt;
				if(ss[tt-1]==')' && tt>0 && s[tt-1]>=0)
					e[i]=e[tt-1];
				w=i-e[i]+1;
				fr[w]++;
				ans=max(ans,w);		
			}
			else 
			s[i]=e[i]=-1;
		}
	}
	
	cout<<ans<<" "<<fr[ans];
}

// driver function
int main() {
    fast_io;
    ll tc=1; //cin >> tc; 
    while (tc--) {
        sol();
        cout << endl;
    }

   return 0;
}

