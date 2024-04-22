Single source shortest path with negative weight edges in directed graph.

1. Distance from the Source (Bellman-Ford Algorithm) -----GFg
2. https://cses.fi/problemset/task/1197 //printing negative cycle path also.
1. solution 
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int n, vector<vector<int>>& v, int s) {
        // Code here
        vector<int> dis(n,1e8);
        dis[s]=0;
        int t=n-1;
        while(t--)
        {
        for(auto val : v)
        {
            int u=val[0];//node-1
            int v=val[1];//node-2
            int wt=val[2];//weight
            if(dis[u]+wt<dis[v])
            {
                dis[v]=dis[u]+wt;
            }
        }
        }

        for(auto val : v)
        {
            int u=val[0];
            int v=val[1];
            int wt=val[2];
            if(dis[u]+wt<dis[v])
            {
                return {-1};//negative cycle
            }
        }
        return dis;
    }
};

2. Solution
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
#define inpt(v) fl(i,(ll)v.size()) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
#define pr(x)   cout<<x;nl;
#define yn(ok)  cout << (ok?"Yes\n" :"No\n");
//Constants
const int M = 1e9+7; 
const int N = 2505;
const ld pi = 3.141592653589793238;                                                                               
const ll INF = 9e18;
const ld eps = 1e-6;
 
ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
vector<pair<pair<ll,ll>,ll>> edges;
void solve()
{
    //START
    cin>>n>>m;
    fl(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        edges.pus({{u,v},w});  
    }
    vl dis(n,1e8);
    vl par(n,-1);
    dis[0]=0;
    for(ll i=0;i<=n-1;i++)
    {
        //performing n-1 relaxations
        for(auto val : edges )
        {
            ll u =val.ff.ff,v=val.ff.ss,w=val.ss;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                par[v]=u;//this change.
            }
        }
    }
    //performing one more relaxation - if distance still decrease  then there is negative cycle.
    bool is_negative_cycle=false;
    ll cycle_start;
    for(auto val : edges )
    {
        ll u =val.ff.ff,v=val.ff.ss,w=val.ss;
        if(dis[u]+w<dis[v])
        {
            dis[v]=dis[u]+w;
            is_negative_cycle = true;
            par[v]=u;
            cycle_start=v;
        }
    }
    if(!is_negative_cycle)
    {
        na;return;
    }
    ya;
    /*this point 'cycle_start' will be either on negative cycle or reachable from it.
    so  To get the vertices that are guaranteed to lie in a negative cycle,
    starting from the vertex pass through to the predecessors n times*/
    ll y = cycle_start;
    
    for (ll i=0;i<n;i++)
    {
        y=par[y];
    }
    vector<ll> path;
    // prt(par);
    for (ll cur = y;; cur = par[cur]) 
    {
        path.push_back(cur);
        // dbg(cur);
        // dbg(par[cur]);
        if (cur == y && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());
    // cout << "Negative cycle: ";
    for(auto val : path)
    {
        cout<<val+1<<" ";
    }
    nl;
    //END
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*__builtin_popcountll(x) , */
