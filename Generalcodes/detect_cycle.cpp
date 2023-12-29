    
    
    
//Problem : https://codeforces.com/contest/711/problem/D

/////////////////////////////////////////////|| जय श्री राम ||//////////////////////////////////////

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
const int M = 1e9+7; //998244353
const int N = 2e5+10;
const ld pi = 3.141592653589793238;                                                                               
const ll INF = 9e18;
const ld eps = 1e-6;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

/////////////////////////////////////////////|| हर हर महादेव ||/////////////////////////////////////

ll cs = -1, ce  = -1;

//personal opinion better to use 'bool' one below but this also works (undirected graph) 
//accepted in round trip cses 

// void  dfs(ll v,ll pr,vl &vis,vl &par,vector<vector<ll>> &g )
// {
//     dbg(v);
//     vis[v] = 1;par[v] = pr;
//     for(auto child : g[v])
//     {
//         if(child==pr) continue;
//         if(vis[child])
//         {
//             cout<<v<<" "<<child<<endl;
//             cs = child,ce = v;
//             continue;
//             // return; 
//         }
//         dfs(child,v,vis,par,g);
//     }
// }


//--------> directed graph 
//this will also work for detect cycle doesn't care about how many cycles in graph 

bool  dfs(ll v,ll pr,vl &vis,vl &par,vector<vector<ll>> &g )
{
    vis[v] = 1;
    dbg(v);
    for(auto child : g[v])
    {
        if(child==pr) continue;
        if(vis[child])
        {
            cout<<v<<" "<<child<<endl;
            cs = child,ce = v;
            return true; 
        }
        par[child] = v;
        if(dfs(child,v,vis,par,g)) return true;
    }
    return false;
}


/////////////////////////////////////////////|| जय भोलेनाथ  ||/////////////////////////////////////

void solve()
{
    //START
    cin>>n;
    vector g(n,vl());
    cin>>m;
    while(m--)
    {
        cin>>a>>b;
        a--;b--;
        g[a].pus(b);
        g[b].pus(a);
    }
    vl vis(n,0),par(n,-1);
    dfs(0,-1,vis,par,g);
    dbg(cs);
    dbg(ce);
    prt(par);
    //END
}

/////////////////////////////////////////////|| जय महाकाल  ||/////////////////////////////////////

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

/////////////////////////////////////////////|| ॐ नमः शिवाय ||/////////////////////////////////////
