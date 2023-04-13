//Prims Algo using Priority Queue 

QUestion : Minimum Spanning Tree -----> Gfg
     public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	//prims algorithm
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>> > q;
        q.push({0,0});
        vector<int> vis(V+1,0);
        int sum=0;
        while(!q.empty())
        {
            auto it = q.top();
            int wt=it.first;
            int node = it.second;
            q.pop();
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(auto val : adj[node])
            {
                int wtt=val[1];
                int node=val[0];
                if(!vis[node])
                {
                    q.push({wtt,node});
                }
            }
        }
        return sum;
    }
    
//Krushkal's Algorithm using DSU

Question : Codeforces 1245 D 
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
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
#define pr(x)   cout<<x<<endl;
#define yn(ok)  cout << (ok?"Yes\n" :"No\n");
//Constants
const int M = 1e9+7; 
const int N = 2e3+5;
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
string s,s1,s2;
bool f,g;
char d,e;
vl parent(N);
vl Size(N);
void make(ll v)
{
    parent[v]=v;
    Size[v]=1;
}
ll find(ll v)
{
    if(parent[v]==v) return v;
    //pathcompression
    return  parent[v]=find(parent[v]);
}
void Union(ll a,ll b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(Size[a]<Size[b])  swap(a,b);
    parent[b]=a;
    Size[a]+=Size[b];
}
void solve()
{
    //START
    cin>>n;
    vector<pair<ll,ll>> cities(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>cities[i].first>>cities[i].second;
    }
    vector<ll> c(n+1);
    vector<ll> k(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(ll i=1;i<=n;i++)
    {
        cin>>k[i];
    }
    vector<pair<ll,pair<ll,ll>>> edges;
    for(ll i=1;i<=n;i++)
    {
        edges.push_back({c[i],{i,0}});
    }
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            ll dis=abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second);
            ll cost=dis*(k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }
    ll total=0;

    vector<ll> stations;

    vector<pair<ll,ll>> connections;

    sort(all(edges));

    for(ll i=0;i<=n;i++) 
    {
        make(i);
    }

    for(auto &edge : edges)
    {
        ll w=edge.first;
        ll u=edge.second.first;
        ll v=edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        if(u==0 or v==0)
        {
            stations.push_back(max(u,v));
        }
        else
        {
            connections.push_back({u,v});
        }
        total+=w;
    }
    cout<<total<<endl;
    cout<<stations.size()<<endl;
    for(auto val : stations)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto val : connections)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
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
/*__builtin_popcountll(x) , */
