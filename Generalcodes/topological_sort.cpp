Question ---> https://www.spoj.com/problems/TOPOSORT/

//typing 
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long long;
using ld  = long double;
//Constants
const int M = 1e9+7; 
const int N = 1e4+5;
const ll INF = 9e18;
 
//Let's Go :)
vector<ll> graph[N];
 
vector<bool> vis;//visited array
vector<ll> level[N];
vector<ll> ans;
vector<ll> ind;
// void dfs()
void solve()
{
    ll n,m;
    cin>>n>>m;
    ind.assign(n+1,0);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        ind[v]++;
    }
    vis.assign(n+1,false);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=1;i<=n;i++)
    {
        if(ind[i]==0) pq.push(i);
    }
    while(!pq.empty())
    {
        ll v=pq.top();pq.pop();
        ans.push_back(v);
        for(auto val : graph[v])
        {
            ind[val]--;
            if(ind[val]==0) pq.push(val);
        }
    }
    if(ans.size()!=n)
    {
        cout<<"Sandro fails."<<endl;return;
    }
    for(auto val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
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
