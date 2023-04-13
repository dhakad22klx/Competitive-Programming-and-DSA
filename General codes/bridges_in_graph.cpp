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
vector<ll> graph[N];

bool vis[N];//visited array

vector<ll> level[N];

void dfs(ll node, ll parent, vector<ll> &vis, vector<ll> &tin, vector<ll> &low, ll &timer, vector<ll> graph[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: graph[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, graph); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;//bridges node -it
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
void solve(){
    ll n,m;
    cin >> n >> m; 
    for(int i = 0;i<m;i++) {
        ll u, v;
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }
    
    vector<ll> tin(n, -1);
    vector<ll> low(n, -1); 
    vector<ll> vis(n, 0); 
    ll timer = 0; 
    for(ll i = 0;i<n;i++) {
        if(!vis[i]) {
            dfs(i, -1, vis, tin, low, timer, graph); 
        }
    }
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
