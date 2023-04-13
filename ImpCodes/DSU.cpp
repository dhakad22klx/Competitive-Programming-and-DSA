Fatland is a town that started with N distinct empires, namely empires 1, 2, ..., N. But over time, the armies of some of these empires have taken over other ones. Each takeover occurred when the army of empire i invaded empire j. After each invasion, all of empire j became part of empire i, and empire j was renamed as empire i.

Empire Huang, leader of Badland, wants to invade Fatland. To do this, he needs to calculate how many distinct empires still remain in Fatland after all the takeovers. Help him with this task.

//code DSU
#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
#define fl(i,n)   for(ll i = 0; i < n; ++i)

typedef vector<ll> vl;

//algo
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)

//IO
#define nl      cout<< "\n";
#define ya      cout<<"YES\n";
#define na      cout << "NO\n";
#define inpt(v) fl(i,v.size()) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
//Constants
const int M = 1e9+7; 
const int N = 5e5+5;
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
string s,s1,s2;
bool f,g;
char d,e;
ll parent[N];
ll Size[N];
void make (ll v)
{
    parent[v]=v;
    Size[v]=1;
}
ll find(ll v)
{
    if(v==parent[v]) return v;
    //Path compression
    return parent[v] = find(parent[v]);
}
void Union(ll a,ll b)
{
    a=find(a);
    b=find(b);
    //Union by size 
    if(a==b) return;
    if(Size[a]<Size[b]) swap(a,b);
    parent[b]=a;
    Size[a]+=Size[b];
}
void solve()
{
    //START
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        make(i);
    }
    while(k--)
    {
        cin>>x>>y;
        Union(x,y);
    }
    ans=0;
    for(ll i=1;i<=n;i++) if(i==find(i)) ans++;
    cout<<ans<<endl;return;
    //END
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





Codeforces 25 D

#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
#define fl(i,n)   for(ll i = 0; i < n; ++i)

typedef vector<ll> vl;

//algo
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)

//IO
#define nl      cout<< "\n";
#define ya      cout<<"YES\n";
#define na      cout << "NO\n";
#define inpt(v) fl(i,v.size()) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
//Constants
const int M = 1e9+7; 
const int N = 5e5+5;
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
string s1,s2;
bool f,g;
char d;
ll parent[N];
ll Size[N];
multiset<ll> s;
void make (ll v)
{
    parent[v]=v;
    s.insert(v);
    Size[v]=1;
}
ll find(ll v)
{
    if(v==parent[v]) return v;
    //Path compression
    return parent[v] = find(parent[v]);
}
void merge(ll a,ll b)
{
    //s.erase(s.find(a));
    s.erase(s.find(b));
    //s.insert(Size[b]+Size[a]);
}
multiset<pair<ll,ll>> edges;
void Union(ll a,ll b)
{
    a=find(a);
    b=find(b);
    //Union by size 
    if(a==b) 
    {
        f=true;return;
    }
    if(Size[a]<Size[b]) swap(a,b);
    merge(a,b);
    parent[b]=a;
    Size[a]+=Size[b];
}
void solve()
{
    //START
    cin>>k;
    for(ll i=1;i<=k;i++)
    {
        make(i);
    }
    k--;
    while(k--)
    {
        cin>>x>>y;
        f=false;
        Union(x,y);
        if(f){edges.insert({x,y});}
        // if(s.size()==1)
        // {
        //     cout<<0<<endl;
        // }
        // else
        // {
        //     c=1e9;a=0;
        //     for(auto val : s)
        //     {
        //        if(a) c=min(c,val-a);
        //        a=val;
        //     }
        //     cout<<c<<endl;
        // }
    }
    a=*(s.begin());
    s.erase(s.find(a));
    cout<<s.size()<<endl;
    if(s.size()==0) return;
    //prt(s);
    //cout<<find(20)<<" "<<find(1)<<endl;
    while(!s.empty())
    {
        pair<ll,ll> p = *(edges.begin());
        cout<<p.first<<" "<<p.second<<" "<<*(s.begin())<<" "<<a<<endl;
        // cout<<p.first<<" "<<p.second<<" "<<p.first<<" "<<*(s.begin())<<endl;
        s.erase(s.begin());
        edges.erase(edges.begin());
    }
    //END
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
