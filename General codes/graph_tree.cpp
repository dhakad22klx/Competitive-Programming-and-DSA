1. Height and depth of nodes in tree for tree thier is no need of visited in dfs
// n-nodes , n-1 edges
vector<ll> graph[N];

//bool vis[N];//visited array

vector<ll> height(N);

vector<ll> depth(N);

void dfs(ll vertex,ll par){
    /*Take action on the vertex
    * after entering the vertex
    */

    //vis[vertex]=true;
    //cout<<vertex<<endl;

    for(ll child : graph[vertex])
    {
        //cout<<"Parent "<<vertex<<" Child "<<child<<endl;

        if(child == par) continue;

        /*Take action on the child 
        before entering to the child node*/

        depth[child]= depth[vertex]+1;

        dfs(child,vertex);

        height[vertex]=max(height[vertex],height[child]+1);

        /*Take action on child after exiting child node*/
    }

    /*Take action on the vertex before exiting the vertex*/
    return;
}
void solve()
{
    ll n;
    cin>>n;//n-no of vertices
    // in a tree n-nodes then n-1 edges

    for(ll i=0;i<n-1;i++)
    {
        ll v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1,0);//or write void dfs(ll vertex,ll par=0)

    for(ll i=1;i<=n;i++){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
}





2. 
