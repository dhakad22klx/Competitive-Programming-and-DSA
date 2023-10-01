/////////////////////////|| जय भोलेनाथ ||//////////////////////
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
//DataTypes
using ll  = long  long int;
using ld  = long double;

#define all(x)    x.begin(), x.end()
#define allr(x)   x.rbegin(),x.rend()
#define fl(i,n)   for(ll i = 0; i < n; ++i)
#define ff        first
#define ss        second
#define pus       push_back
#define bb        begin()
#define ee        end()
#define dbg(x)    cout<<#x<<" = "<<x<<'\n';

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
#define inpt(v) fl(i,(ll)v.size()) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
#define pr(x)   cout<<x;nl;
#define yn(ok)  cout << (ok?"Yes\n" :"No\n");
//Constants
const int M = 1e9+7; 
const int N = 2e5+10;
const ld pi = 3.141592653589793238;                                                                               
const ll INF = 9e18;
const ld eps = 1e-6;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

//String Hashing : preprocessing hash function (polynomial string hashing)
//Refer : https://cp-algorithms.com/string/string-hashing.html#calculation-of-the-hash-of-a-string
//Refer : CP Handbook

vector<ll> h,p;//h-hash,p-power 
ll A,B;
void compute_hash(string &s)
{
    ll n = s.length();
    h.assign(n,0);
    p.assign(n,0);
    //assume constants
    A = s.length()+1,B=1e9+7;//A-should be greater than or equal length of string to avoid risk
    //It is reasonable to make 'A'  a prime number roughly equal to the number of characters in the input alphabet.31 or 51
    h[0]=s[0]-'a' + 1;//solving for lower case
    //h [ k ] contains the hash value of the prefix s [0 . . . k ]
    //h [ k ] = ( h [ k − 1] A + s [ k ]) mod B
    p [0] = 1 ;
    //p [ k ] = ( p [ k − 1] A ) mod B.
    for(ll i=1;i<n;i++)
    {
        h[i] = ((h[i-1]*A)%B + (s[i]-'a' + 1))%B;
    }
    for(ll i=1;i<n;i++)
    {
        p[i] = (p[i-1]*A)%B;
    }
}
//get hash of substring s[a...b],
//string 's' is same for which hash is calculated above

//hash of substring

ll get(ll a,ll b)
{
    ll full  = h[b];
    ll extra = (a-1>=0 ? (h[a-1]*(p[b-(a-1)])) % B : 0);
    return (full - extra + B ) % B;
}
/////////////////////////|| जय श्री राम ||//////////////////////
void solve()
{
    //START
    //Problem : password : codeforces
    //https://codeforces.com/problemset/problem/126/B
    string s;
    cin>>s;
    compute_hash(s);
    // prt(h);
    n=s.length();
    vl v;
    for(ll size = 1;size < n;size++)
    {
        if(get(0,size-1) == get(n-size,n-1)) v.push_back(size);
    }
    string ans = "Just a legend";
    l = 0,r=v.size()-1;
    ll mx =-1;
    while(l<=r)
    {
        ll mid  = (l+r)/2;
        bool f = false;
        for(ll i=1;i+v[mid]<n;i++)
        {
            if(get(0,v[mid]-1)==get(i,i+v[mid]-1))
            {
                f=true;break;
            }
        }
        if(f)
        {
            mx=v[mid];
            l = mid+1;
        }
        else r = mid-1;
    }
    if(mx!=-1) ans=s.substr(0,mx);
    cout<<ans;nl;
    //END
}
/////////////////////////|| जय महाकाल ||//////////////////////
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
