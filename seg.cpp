
#include<bits/stdc++.h>// RMQ FOR SEGMNET TREE
#define ll long long int
#define llu unsigned long long int
#define db double
#define bsa(v,n,a) binary_search(v,v+n,a)
#define bsv(v,a) binary_search(v.begin(),v.end(),a)
#define PI 3.1415926535897932
using namespace std;
const db eps=1e-6;
const db inf=1e9;
const ll INF=1e-15;
const ll mod=1e9+7;
const ll MAX=1e5;
ll n;
ll seg[2*MAX];
void build()
{
    for(ll i=n-1;i>0;--i)
     seg[i]=max(seg[i<<1],seg[i<<1|1]);
}
void modify(int p, int value)
{
  for (seg[p += n] = value; p > 1; p >>= 1)
    seg[p>>1] = max(seg[p],seg[p^1]);
}
ll query(ll l,ll r)
{
    ll res=INT_MIN;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,seg[l++]);
        if(r&1) res=max(res,seg[--r]);
    }
    return res;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   for(ll i=0;i!=n;++i)cin>>seg[n+i];
   build();
   ll m;
   cin>>m;
    while(m--){
        ll l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
 return 0;
}
