
///Range minimum query implementation ------>gives answer to query in O(1)

Problem Link : https://www.spoj.com/problems/RMQSQ/

//extendable to range maximum query  , range gcd query ---gives answer to query in O(1)


#include<bits/stdc++.h>
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
#define fl(i,n)   for(ll i = 0; i < n; ++i)
#define ff                   first
#define ss                   second
#define pus                  push_back
#define bb                   begin()
#define ee                   end()

typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pair<ll,ll>> vpl;


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
#define pr(x)   cout<<x;nl;
#define yn(ok)  cout << (ok?"Yes\n" :"No\n");
//Constants
const int M = 1e9+7; 
const int N = 2e5+10;
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
vector<vector<ll>> _min(N,vector<ll> (17,0));
vector<ll> bin_log(N,0);
void query(ll L,ll R)
{
    ll length=R-L+1;
    k=bin_log[length];
    ans=min(_min[L][k],_min[R-(1<<k)+1][k]);
    pr(ans);
}
void solve()
{
    //START
    cin>>n;// nmax=1e5 ,log(nmax)=16;
    vl v(n);
    inpt(v);
    bin_log[1]=0;
    for(ll i=2;i<=n;i++)
    {
        bin_log[i]=bin_log[i/2]+1;
    }
    fl(i,n)
    {
        _min[i][0]=v[i];
    }
    for(ll k=1;k<17;k++)
    {
        for(ll i=0;i+(1<<k)-1<n;i++)
        {
            _min[i][k]=min(_min[i][k-1],_min[i+(1<<(k-1))][k-1]);
        }
    }
    cin>>q;
    while(q--)
    {
        ll L,R;
        cin>>L>>R;
        query(L,R);
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
