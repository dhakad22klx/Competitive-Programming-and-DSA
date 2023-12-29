/////////////////////////|| जय भोलेनाथ ||//////////////////////
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
#define fl(i,n)   for(ll i = 0; i < n; ++i)
#define ff        first
#define ss        second
#define pus       push_back
#define bb        begin()
#define ee        end()
#define dbg(x)    cout<<#x<<" = "<<x<<'\n';

typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pair<ll,ll>> vpl;


//algo
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)

//IO
#define nl      cout<< "\n";
#define ya      cout<<"YES\n";
#define na      cout << "NO\n";
#define inpt(v) fl(i,(ll)v.size()) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
#define pr(x)   cout<<x;nl;
#define yn(ok)  cout << (ok?"Yes\n" :"No\n");
//Constants
const int M = 1e9+7; 
const int N = 2e5+10;
const ld pi = 3.141592653589793238;                                                                               
const ll INF = 9e18;
const ld eps = 1e-6;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

//changing value  to 'value' at particular index query_l==query_h;

void build(ll node,ll node_l,ll node_h,ll query_l,ll query_h,ll value, vl &tree)
{
    if(query_l <= node_l and node_h<=query_h) 
    {
        tree[node]=value;return;
    }
    if(query_h<node_l or query_l>node_h) return;

    ll last_in_left = (node_l+node_h)/2;

    build(2*node,node_l,last_in_left,query_l,query_h,value,tree);

    build(2*node + 1,last_in_left+1,node_h,query_l,query_h,value,tree);

    tree[node] = __gcd(tree [2*node] , tree [2*node + 1]);
    //whatever we want min,max,xor,gcd here will be changes accordingly 
}

//getting value for rangle query_l to query_h

ll get(ll node,ll node_l,ll node_h,ll query_l,ll query_h,vl &tree)
{
    if(query_l <= node_l and node_h <= query_h) 
    {
        return tree[node];
    }
    if(query_h<node_l or query_l>node_h) return 0;

    ll last_in_left = (node_l+node_h)/2;

    ll a = get(2*node,node_l,last_in_left,query_l,query_h,tree);

    ll b = get(2*node+1,last_in_left+1,node_h,query_l,query_h,tree);

    return __gcd(a,b);
    //whatever we want min,max,xor,gcd here will be changes accordingly 
}
/////////////////////////|| जय श्री राम ||//////////////////////
void solve()
{
    //START

    //Problem : 1549 D codeforces 
    
    cin>>n;
    vl v1;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        v1.push_back(x);
    }
    if(n==1){cout<<1;nl;return;}
    vl v;
    for(ll i=0;i<n-1;i++)
    {
        v.push_back(abs(v1[i+1]-v1[i]));
    }
    n=v.size();
    while((n&(n-1)))
    {
        //pushing 0 into vector is not really necessary 
        //as we not gonna be iterating those indices
        n++;
    }
    vl tree(2*n,0);  
    for(ll i=0;i<v.size();i++)
    {
        build(1,0,n-1,i,i,v[i],tree);//adding value at index i 
    }

    //solving problmes  using binary search 
    //it is giving TLE i dont know why
    // ll ans=0;
    // ll l = 1,r=v.size();
    // while(l<=r)
    // {
    //     ll mid  = (l + r)/2;
    //     bool f = false;
    //     for(ll i=0;i+mid-1<v.size();i++)
    //     {
    //         f |= (get(1,0,n-1,i,i+mid-1,tree)>1);
    //     }
    //     if(f)
    //     {
    //         ans=mid;l=mid+1;
    //     }
    //     else r=mid-1;
    // }
    // cout<<ans+1;nl;

    //Solving using two pointers it passes 

    ll ans=0;
    for(ll l=0,r=0;r<v.size();)
    {
        ll cur = get(1,0,n-1,l,r,ref);
        if(cur>1) ans=max(ans,r-l+1),r++;
        else if(l<r) l++;
        else r++;
    }
    cout<<ans+1;nl;

    //END
}
/////////////////////////|| जय महाकाल ||//////////////////////
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*__builtin_popcountll(x) , */
