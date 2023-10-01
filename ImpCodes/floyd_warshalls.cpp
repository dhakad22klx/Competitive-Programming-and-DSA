Note : dis[i][i]==0 if not mentioned exclusively

1.295 B code forces
2. 25 C codeforces






1. -->
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

vector<bool> vis(N,false);//visited array

vector<vector<ll>> dist(505,vector<ll> (500,0));

/////floyd warshall algorithm/////
void solve()
{
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin>>dist[i][j];
        }
    }
    vector<ll> deletion(n);
    for(ll i=0;i<n;i++)
    {
        cin>>deletion[i];
    }
    reverse(deletion.begin(),deletion.end());
    vector<ll> ans;
    for(ll k=0;k<n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            ll k_v=deletion[k];
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k_v]+dist[k_v][j]);
            }
        }
        ll sum=0;
        for(ll i=0;i<=k;i++)
        {
            for(ll j=0;j<=k;j++)
            {
                sum+=dist[deletion[i]][deletion[j]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;return;
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















///25 C codeforces
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

vector<bool> vis(N,false);//visited array

vector<vector<ll>> dist(505,vector<ll> (505,0));

/////floyd warshall algorithm/////
void solve()
{
    ll n;cin>>n;ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            cin>>dist[i][j];
            sum+=dist[i][j];
        }
    }
    sum=sum/2;//as we summed 2 times distance
    //cout<<sum<<endl;
    ll k;cin>>k;
    while(k--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(c<dist[a][b]){
            //sum-=(dist[a][b]-c);
            //cout<<sum<<" ";
            dist[a][b]=c;
            dist[b][a]=c;
        }
        //else cout<<sum<<" ";
        sum=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],min(dist[i][a]+dist[a][b]+dist[b][j],dist[i][b]+dist[b][a]+dist[a][j]));
                sum+=dist[i][j];
            }
        }
        cout<<sum/2<<" ";
        // ll ans=0;
        // for(ll i=1;i<=n;i++)
        // {
        //     for(ll j=1;j<=n;j++)
        //     {
        //         ans+=dist[i][j];
        //     }
        // }
        // cout<<ans/2<<" ";

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
