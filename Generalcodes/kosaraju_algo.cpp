COdeforce ---> 427 C
//order from dfs1 basically reversed  topological sort sorted   (actually this is exactly what vertices' sort by exit time means ;
//उम्मिद तो नहीं है लेकिन देखते हैं
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define fl(i,n)   for(ll i = 0; i < n; ++i)

typedef vector<ll> vl;

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
//Constants
const int M = 1e9+7; 
const int N = 5e5+5;
const ll INF = 9e18;

ll n,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

vector<ll> g[N];

vector<ll> tg[N];//transpose of g

vector<bool> vis(N,false);

vector<ll> order;

vector<vector<ll>> scc;

vector<ll> temp;

void dfs1(ll i)
{
    vis[i]=true;
    for(auto child : g[i])
    {
        if(!vis[child])
        {
            dfs1(child);
        }
    }
    order.push_back(i);
}
void dfs2(ll i)
{
    vis[i]=true;
    temp.push_back(i);
    for(auto child : tg[i])
    {
        if(!vis[child])
        {
            dfs2(child);
        }
    }
}

void solve()
{
    //START
    cin>>n;
    vl cost(n);
    inpt(cost);
    ll m;
    cin>>m;
    while(m--)
    {
        cin>>a>>b;a--;b--;
        g[a].push_back(b);
        tg[b].push_back(a);
    }
    for(ll i=0;i<n;i++)
    {
        if(!vis[i]) dfs1(i);
    }
    for(ll i=0;i<n;i++) vis[i]=false;
    

    for(ll i=n-1;i>=0;i--)
    {
        temp.clear();
        if(!vis[order[i]])
        {
            dfs2(order[i]);
            scc.push_back(temp);
        }
    }
    ans1=0;ans2=1;
    for(auto vec : scc)
    {
        mn=1e9;
        // ans2=(ans2%M)*(vec.size()%M);
        // ans2%=M;
        for(auto val : vec)
        {
            mn=min(mn,cost[val]);
        }
        ans1+=mn;
        k=0;
        for(auto val : vec)
        {
            if(cost[val]==mn) k++;
        }
        ans2*=k;
        ans2%=M;
    }
    cout<<ans1<<" "<<ans2<<endl;return;
    //END
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*__builtin_popcountll(x) ,ogla ujarasok */
