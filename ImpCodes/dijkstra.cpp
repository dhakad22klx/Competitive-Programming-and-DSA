//1.normal ide dijkstra implementation ,
//2.leetcode ide dijkstra implementation,
//3.Printing shortest distance path from soruce to destinaton//single source
//
//

1.

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

vector<pair<ll,ll>> graph[N];

vector<bool> vis(N,false);//visited array

vector<ll> dist(N,INF);

void dijkstra(ll source)
{
    set<pair<ll,ll>> st;

    st.insert({0,source});

    dist[source]=0;

    while(!st.empty())
    {
        auto node = *st.begin();

        ll v = node.second;

        ll dist_v = node.first;

        st.erase(st.begin());

        if(vis[v]) continue;

        vis[v]=true;

        for(auto child : graph[v])
        {
            ll child_v=child.first;

            ll wt=child.second;//wt-weight

            if(dist[v] + wt < dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                
                st.insert({dist[child_v],child_v});
            }
        }
    }
    //Time Complexity - V+E*log(V)----> Vertices ,E edges 
}

void solve()
{
    ll n,m;

    cin>>n>>m;
    //vector<pair<ll,ll>> graph[N];
    for(ll i=0;i<m;i++)
    {
        ll node1,node2,weight;
        cin>>node1>>node2>>weight;
        //undirected graph
        graph[node1].push_back({node2,weight});//only this will be if directed graph
        graph[node2].push_back({node1,weight});
    }
    // for(ll i=1;i<=n;i++){
    //     for(auto val : graph[i]){
    //         cout<<val.first<<" "<<val.second<<endl;
    //     }
    //     cout<<endl;
    // }
    dijkstra(1);

    for(ll i=2;i<=n;i++)
    {
        dist[i]==INF ? cout<<-1<<" " : cout<<dist[i]<<" ";//minimum distance of any node from source node 
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


















2.
////leetcode
class Solution {
public:
    const int N=2e2+10;
    const int INF=1e9+10;
    int dijkstra(int source, vector<pair<int,int>> g[],int n){
        vector<bool> vis(N,false);
        vector<int> dist(N,INF);
        // vis[source]=true;
        // dist[source]=true;
        set<pair<int,int>> st;
        st.insert({0,source});
        dist[source]=0;
        while(!st.empty())
        {
            //pair<int,int> 
            auto node = *st.begin();
            int v=node.second;
            int dis_v=node.first;
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v]=true;
            for(auto child : g[v]){
                int child_v = child.first;
                int wt   =  child.second;
                if(dist[v]+wt<dist[child_v]){
                    dist[child_v]=dist[v]+wt;
                    st.insert({dist[child_v],child_v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INF) return -1 ;
            ans=max(ans,dist[i]);
        }
        return ans;
        
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<pair<int,int>> g[N];//v[0],v[1]--nodes,v[2]-weight
        for(auto val : times){
            g[val[0]].push_back({val[1],val[2]});
        }
        return dijkstra(k,g,n);
        
        
    }
};













3.

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

vector<pair<ll,ll>> graph[N];

vector<bool> vis(N,false);//visited array

vector<ll> dist(N,INF);

vector<ll> path_parent(N);

void dijkstra(ll source)
{
    set<pair<ll,ll>> st;

    st.insert({0,source});

    dist[source]=0;

    while(!st.empty())
    {
        auto node = *st.begin();

        ll v = node.second;

        ll dist_v = node.first;

        st.erase(st.begin());

        if(vis[v]) continue;

        vis[v]=true;

        for(auto child : graph[v])
        {
            ll child_v=child.first;

            ll wt=child.second;//wt-weight

            if(dist[v] + wt < dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                
                st.insert({dist[child_v],child_v});

                path_parent[child_v]=v;
            }
        }
    }
}

void solve()
{
    ll n,m;

    cin>>n>>m;
    //vector<pair<ll,ll>> graph[N];
    for(ll i=0;i<m;i++)
    {
        ll node1,node2,weight;
        cin>>node1>>node2>>weight;
        //undirected graph
        graph[node1].push_back({node2,weight});//only this will be if directed graph
        graph[node2].push_back({node1,weight});
    }
    // for(ll i=1;i<=n;i++){
    //     for(auto val : graph[i]){
    //         cout<<val.first<<" "<<val.second<<endl;
    //     }
    //     cout<<endl;
    // }
    dijkstra(1);

    if(dist[n]==INF) {cout<<-1<<endl;return;}

    vector<ll> path;path.push_back(n);
    ll a=n;
    while(path_parent[a]!=1)
    {
        path.push_back(path_parent[a]);
        a=path_parent[a];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    for(auto val : path)
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
