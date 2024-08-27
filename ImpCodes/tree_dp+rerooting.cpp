Problem 1 : https://codeforces.com/contest/161/problem/D //refrence Kartik arora youtube 
Proble  2 : more advance version of Problem 1 here weight also plays role.
//can read akhil commented  solution for understand 

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
ll sub[50001][501],sub2[50001][501];
//sub -- for subtree, 
//sub2 --- for overall ,
void dfs(ll v,ll par,vector<vector<ll>> &g)
{
    for(auto child : g[v])
    {
        if(child!=par) dfs(child,v,g);
    }
    sub[v][0]=1;
    for(ll j=1;j<=k;j++)
    {
        for(auto child : g[v])
        {
            if(child!=par) sub[v][j]+=sub[child][j-1];
        }
    }
}
void dfs2(ll v,ll par,vector<vector<ll>> &g,ll up)
{
    ll cur=sub[v][k]+up;
    ans+=cur;
    for(ll j=0;j<=k;j++)
    {
        sub2[v][j]=sub[v][j];
    }
    if(par!=-1)
    {
        for(ll j=0;j<=k;j++)
        {
            sub2[v][j]+=(j>=1 ? sub2[par][j-1] : 0);
            sub2[v][j]-=(j>=2 ? sub[v][j-2]   : 0);
        }
    }
    for(auto child : g[v])
    {
        if(child!=par)
        {
            dfs2(child,v,g,sub2[v][k-1]-(k>=2 ? sub[child][k-2] : 0));
        }
    }
}
/////////////////////////||जय श्री राम||//////////////////////
void solve()
{
    //START
    cin>>n>>k;
    vector g(n,vl());
    fl(i,n-1)
    {
        ll u,v;cin>>u>>v;u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1,g);
    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<=k;j++)
    //     {
    //         cout<<sub[i][j]<<" ";
    //     }
    //     nl;
    // }
    ans=0;
    dfs2(0,-1,g,0);
    // for(ll i=0;i<n;i++)
    // {
    //     ans+=sub2[i][k];
    // }
    ans/=2;
    cout<<ans;nl;
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



Problem 2 solution : 


    
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

vector<vector<ll>> sub,fr,fr2,sub2;

//fr-frequency of particular edges to be considered and sub --total wight considering frequency 
//sub,fr ---subtree
//sub2,fr2 --- overall 

void dfs(ll v,ll par, vector<vpl> &g)
{
    fr[v][0]=1;
    for(auto [child,w] : g[v])
    {
        if(child!=par)
        {
            dfs(child,v,g);
            fr[v][0] += fr[child][2];
            fr[v][1] += fr[child][0];
            fr[v][2] += fr[child][1];
            sub[v][0] += w*fr[child][2] + sub[child][2];
            sub[v][1] += w*fr[child][0] + sub[child][0];
            sub[v][2] += w*fr[child][1] + sub[child][1];
        }
    }
}


void  get(ll v,ll par,ll wt,vector<vpl> &g, ll up)
{
    ll cur = up + sub[v][1] + 2*sub[v][2];
    ans = min(ans,cur);
    fl(i,3) fr2[v][i]=fr[v][i],sub2[v][i] = sub[v][i];
    if(par!=-1)
    {
        fr2[v][0]+=fr2[par][2];
        fr2[v][0]-=fr[v][1];
        fr2[v][1]+=fr2[par][0];
        fr2[v][1]-=fr[v][2];
        fr2[v][2]+=fr2[par][1];
        fr2[v][2]-=fr[v][0];
        sub2[v][0]+= (sub2[par][2] - (sub[v][1] + wt*fr[v][1])) + (wt*(fr2[par][2]-fr[v][1]));
        sub2[v][1]+= (sub2[par][0] - (sub[v][2] + wt*fr[v][2])) + (wt*(fr2[par][0]-fr[v][2]));
        sub2[v][2]+= (sub2[par][1] - (sub[v][0] + wt*fr[v][0])) + (wt*(fr2[par][1]-fr[v][0]));
    }
    for(auto [child,w] : g[v])
    {
        if(child==par) continue;
        ll x = sub2[v][0] - (sub[child][2] + w*fr[child][2]) + (w*(fr2[v][0]-fr[child][2]));
        ll y = sub2[v][1] - (sub[child][0] + w*fr[child][0]) + (w*(fr2[v][1]-fr[child][0]));
        get(child,v,w,g,x + 2*y);
    }

}


/////////////////////////////////////////////|| जय भोलेनाथ  ||/////////////////////////////////////

void solve()
{
    //START
    cin>>n;
    vector<vector<pair<ll,ll>>> g(n);
    for(ll i=1;i<=n-1;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;u--;v--;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    fr.assign(n,vl(3,0));
    fr2.assign(n,vl(3,0));
    sub.assign(n,vl(3,0));
    sub2.assign(n,vl(3,0));
    dfs(0,-1,g);
    ans = INF;
    get(0,-1,-1,g,0);
    cout<<ans;nl;
    //END
}

/////////////////////////////////////////////|| जय महाकाल  ||/////////////////////////////////////

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

/////////////////////////////////////////////|| ॐ नमः शिवाय ||/////////////////////////////////////
