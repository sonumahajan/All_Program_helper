#include<bits/stdc++.h>
#include<string>
#define ll long long
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define repd(i,a,b) for(ll i=a;i>=b;i--)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define MOD 1000000009
#define vi vector<ll>
#define vl vector<ll>
#define pb push_back
#define nl cout<<"\n"
#define cm cout<<"-1\n"
using namespace std;


     ll h=5;
     ll MAX = 100000 , MIN = -100000;
     ll b_p=0;
     ll a[]={3,89,11,34,65,2,8,14,7,8,11,99,33,1,8,77,12,76,14,8,22,51,90,33,19,87,7,3,1,9,10,99};;
int minimax(ll depth, ll ni,bool mxm, ll alpha,ll beta){
    if (depth == h)
        return a[ni];
 
    if(mxm){
        ll best = MIN;
        for (ll i=0;i<2;i++)
        {
            ll val = minimax(depth+1, ni*2 + i,false, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
 
            if (beta <= alpha){
                b_p++;
                break;
            }
        }
        return best;
    }
    else
    {
        ll best = MAX;
        for (ll i=0;i<2;i++)
        {
            ll val = minimax(depth + 1, ni * 2 + i,true, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha)
                break;
        }
        return best;
    }
}
int main()
{  
    ll ans = minimax(0, 0, true, MIN, MAX);
	cout << "The final optimal value for the original order is : " << ans; nl;
    cout<<"branch pruning for original order: "<<b_p; nl;
    sort(a,a+32);
    ans = minimax(0, 0, true, MIN, MAX);
	cout << "The final optimal value for the good order is : " << ans; nl;
    cout<<"branch pruning for good order: "<<b_p; nl;
    ans = minimax(0, 0, true, MIN, MAX);
	cout << "The final optimal value for the worst order is : " << ans; nl;
    cout<<"branch pruning for worst order: "<<b_p; nl;
	return 0;
}