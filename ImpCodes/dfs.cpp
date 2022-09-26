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
