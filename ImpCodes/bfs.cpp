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

vector<ll> graph[N];

vector<bool> vis(N);//visited array

vector<int> level(N);

void bfs(int source){
    queue<ll> q;
    q.push(source);
    vis[source]=true;
    while(!q.empty()){
        int cur_v=q.front();
        cout<<cur_v<<" ";
        q.pop();
        for(auto child : graph[cur_v]){
            if(vis[child]) continue;
            q.push(child);
            vis[child]=true;
            level[child]=level[cur_v]+1;
        }
    }
    //V+E- v-nodes ,E edges time complexity
    cout<<endl;
}
void solve()
{
    ll n;
    cin>>n;//n-no of vertices ,n-1 -number of edges in case of tree 
    for(ll i=0;i<n-1;i++){
        ll v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<" : "<<level[i]<<endl;
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

/*INPUT

13                         
1 2 
1 3
1 13 
2 5 
5 6
5 7              
5 8
8 12 
3 4 
4 9
4 10
10 11 

OUTPUT 

1 2 3 13 5 4 6 7 8 9 10 12 11 
1 : 0
2 : 1
3 : 1
4 : 2
5 : 2
6 : 3
7 : 3
8 : 3
9 : 3
10 : 3
11 : 4
12 : 4
13 : 1
*/
