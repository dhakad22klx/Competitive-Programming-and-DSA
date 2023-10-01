1.Good LCA problems : https://codeforces.com/contest/832/problem/D

Problem discussed here  : https://www.spoj.com/problems/LCASQ/
Errichto Video Tutorial : https://www.youtube.com/watch?v=oib-XsjFa-M&list=RDCMUCBr_Fu6q9iHYQCh13jmpbrg&index=1

///-->things to remember -starts
Note:  in this problem  parent[i]<i is not mentioned .
Usual binary lifting precomputations worsk when parent[i]<i (above video at 9th mintue for modificaitons).
  
we have 2 different ways to avoid above conditions.(used in https://codeforces.com/contest/191/problem/C this problem ) 
1. run for loop as this.
void compute()
{
    for(ll i=0;i<n;i++)
    {
        up[i][0]=par[i];
    }
    for(ll j=1;j<18;j++)
    {
        for(ll i=0;i<n;i++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
}
2. inside dfs usual for loop as mentiond in below solutions also.

///--> things to remember -starts
/////////////////////////|| जय भोलेनाथ ||//////////////////////
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define fl(i,n)   for(ll i = 0; i < n; ++i)
#define dbg(x)    cout<<#x<<" = "<<x<<'\n';

const ll MAX_N = 10000;
const ll LOG = 14;

vector<ll> children[MAX_N];//graph
ll up[MAX_N][LOG]; // up[v][j] is 2^j-th ancestor of v
ll depth[MAX_N];

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

//to preprocess Lca and depth

void dfs(ll v)
{
    for(auto child : children[v])
    {
        depth[child]=depth[v]+1;
        up[child][0]=v;
        for(ll j=1;j<LOG;j++)
        {
            up[child][j]=up[up[child][j-1]][j-1];
        }
        dfs(child);
    }
}

// Now to find lca
ll get_lca(ll a,ll b)
{   // O(log(N))
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.->using binary lifting
    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
        if(k & (1 << j)) {
            a = up[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = LOG - 1; j >= 0; j--) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
/////////////////////////||जय श्री राम||//////////////////////
void solve()
{
    //START
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>m;
        for(ll j=0;j<m;j++)
        {
            ll u;cin>>u;
            children[i].push_back(u);//as graph is already tree so 
            //we are taking directed
        }
    }
    dfs(0);
    cin >> q;
    while(q--){
        cin >> a >> b;
        cout << get_lca(a, b) << "\n";
    }
    //END
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
/*__builtin_popcountll(x) , */
/*
input->
3
2 1 2
0
0 
3
1 2
1 1
2 2 
output->
0
1
2


*/

