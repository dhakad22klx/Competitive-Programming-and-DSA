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

ll n,k,a,b,c,q,x,y,l,m,r,ans,ans1,ans2,mx,mn,sum;
string s,s1,s2;
bool f,g;
char d,e;
//Let's Go :)
vector<ll> graph[N];
bool vis[N];//visited array
void dfs(ll vertex){
    /*Take action on the vertex
    * after entering the vertex
    */
    vis[vertex]=true;
    cout<<vertex<<endl;
    for(ll child : graph[vertex]){
        cout<<"Parent "<<vertex<<" Child "<<child<<endl;
        if(vis[child]) continue;
        /*Take action on the child 
        before entering to the child node*/
        dfs(child);
        /*Take action on child after exiting child node*/
    }
    /*Take action on the vertex before exiting the vertex*/
    return;
}

// O(V+E)//time complexity
void solve(){
    cin>>n>>k;//n-no of vertices ,k-number of edges
    for(ll i=0;i<k;i++){
        ll v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
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


//Finding number of connected components : hackerearth dfs tutorial
   #include <iostream>
   #include <vector>
    using namespace std;

    vector <int> adj[10];
    bool visited[10];

    void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }

    void initialize() {
        for(int i = 0;i < 10;++i)
         visited[i] = false;
    }

    int main() {
        int nodes, edges, x, y, connectedComponents = 0;
        cin >> nodes;                       //Number of nodes
        cin >> edges;                       //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;     
     //Undirected Graph 
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }

        initialize();                           //Initialize all nodes as not visited

        for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
             connectedComponents++;
         }
        }
        cout << "Number of connected components: " << connectedComponents << endl;
        return 0;
    }
