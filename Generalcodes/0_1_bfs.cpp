Question - https://www.codechef.com/problems/REVERSE?tab=statement
//typing 
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long long;
using ld  = long double;
//Constants
const int M = 1e9+7; 
const int N = 2e5+5;
const ll INF = 9e18;
 
//Let's Go :)
vector<pair<ll,ll>> g[N];
 
vector<bool> vis;//visited array
vector<ll> level(N,INF);
vector<ll> ans;
vector<ll> ind;
void bfs(ll a)
{
    deque<ll> q;
    q.push_back(a);
    level[a]=0;
    while(!q.empty())
    {
        auto node = q.front();
        q.pop_front();
        for(auto child : g[node])
        {
            ll v=child.first;
            ll wt=child.second;
            if(level[node]+wt<level[v])
            {
                level[v]=level[node]+wt;
                if(wt==0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
}
// void dfs()
void solve()
{
    ll n,m;
    cin>>n>>m;
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }
    vis.assign(n+1,false);
    bfs(1);
    ll ans=level[n];
    if(ans==INF) ans=-1;
    //for(int i=1;i<=n;i++) cout<<level[i]<<" "<<vis[i]<<endl;
    cout<<ans<<endl;return;
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
