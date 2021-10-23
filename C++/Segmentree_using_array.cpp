/*
Limitation - All nodes have memory allocated, so tree size must be < 10^8. Better than link-list.
Segment tree for sum in a range -
UPDATE L R K -> 1 L R K
QUERY  L R   -> 2 L R
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define scani(n) scanf("%d",&n)
#define scanl(n) scanf("%lld",&n)
#define fr(i,n) for(int i=0;i<n;i++)
#define pr cout<<
#define en <<endl
#define sp <<' '
#define MAX 1000000
using namespace std;
typedef long long ll;

int tree[MAX],extra[MAX] ;

int buildtree(int ind,int L,int R)
{
	if(L==R)
	{
		cin>>tree[ind];
		return tree[ind];
	}
	tree[ind]= buildtree(ind<<1,L,(L+R)>>1) + buildtree((ind<<1)+1,((L+R)>>1)+1,R) ;
	return tree[ind];
}
int query(int ind,int L,int R,int l,int r,int ex)
{
	if(l==L and r==R)
		return tree[ind]+ (ex+extra[ind])*(R-L+1);
	int mid=(L+R)>>1;
	if(r<=mid)
		return query(ind<<1,L,mid,l,r,ex+extra[ind]);
	else if(l>mid)
		return query((ind<<1)+1,mid+1,R,l,r,ex+extra[ind]);
	else
		return query(ind<<1,L,mid,l,mid,ex+extra[ind]) + query((ind<<1)+1,mid+1,R,mid+1,r,ex+extra[ind]);
}
void update(int ind,int L,int R, int l,int r,int val)
{
	if(l==L and r==R)
	{
		extra[ind]+=val;
		return;
	}
	tree[ind]+=val*(r-l+1);
	int mid=(L+R)>>1;
	if(r<=mid)
		update(ind<<1,L,mid,l,r,val);
	else if(l>mid)
		update((ind<<1)+1,mid+1,R,l,r,val);
	else
	{
		update(ind<<1,L,mid,l,mid,val);
		update((ind<<1)+1,mid+1,R,mid+1,r,val);
	}
}

main()
{
	int t,q,n ,op,l,r,k=2;
	
	cin>>n>>q;
	buildtree(1,1,n);
	
	while(q--)
	{
		cin>>op>>l>>r;
		if(op==1)
		{
			cin>>k;
			update(1,1,n,l,r,k);
		}
		else
			cout<< query(1,1,n,l,r,0) en;		
	}
	
}


