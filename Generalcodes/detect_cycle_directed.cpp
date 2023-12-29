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
#define ff                   first
#define ss                   second
#define pus                  push_back
#define bb                   begin()
#define ee                   end()
#define dbg(x) cout<<#x<<" = "<<x<<'\n';
 
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
#define inpt(v) fl(i,v.size()) cin >> v[i];
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
vl col;
vl par;
vl g[N];

bool dfs(ll v) 
{
    col[v]=1;
    for(auto child : g[v])
    {
        if(col[child]==0)
        {
            par[child]=v;
            if(dfs(child)) return true;
        }
        else if(col[child]==1)
        {
            x=v,y=child;
            return true;
        }
    }
    col[v]=2;
    return false;
}

void solve()
{
    //START
    cin>>n>>m;
    col.assign(n+1,0);
    par.assign(n+1,0);
    fl(i,m)
    {
        cin>>a>>b;
        g[a].pus(b);
    }
    x=-1,y=-1;
    for(ll i=1;i<=n;i++)
    {
        if(col[i]==0)  dfs(i);
        else continue;
        if(x!=-1)
        {
            vl cycle;
            cycle.pus(x);
            while(x!=y)
            {
                x=par[x];
                cycle.pus(x);
            }
            reverse(all(cycle));//order matters ----->
            cycle.pus(cycle[0]);
            pr(cycle.size());
            prt(cycle);return;
        }
    }
    pr("IMPOSSIBLE");
    return;
    //END
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*__builtin_popcountll(x) , */
