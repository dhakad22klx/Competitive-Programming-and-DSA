//typing 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
//DataTypes
using str =  string;
using ll  = long long;
using ld  = long double;


#define FL(i, a, b)          for(ll i = (ll)a; i <(ll) b; ++i)
#define fl(i,n)              FL(i, 0, n)
#define rfl(i,n)             for(ll i=(ll)(n)-1;i>=0;i--)
#define all(x)               x.begin(), x.end()
#define pus                  push_back
#define pub                  pop_back
#define mp                   make_pair
#define ff                   first
#define ss                   second
#define bb                   begin()
#define ee                   end()

#define umap unordered_map
#define uset unordered_set

typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pair<ll,ll>> vpl;
typedef vector<vector<ll>> matrix;// x(n,vector<ll> (m,0) )//n*m
typedef map<ll,ll>   mll;       
typedef tree<int,null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define maxheap(DT)       priority_queue< DT,vector<DT> > 
#define minheap(DT)       priority_queue< DT,vector<DT>,greater<DT> > 
#define present(container, element)   (container.find(element) != container.end()) // for map,set
#define cpresent(container, element)  (find(all(container), element) != container.end()) // for vector 

//algorithms
#define sl(k,s)   ll k=s.length(); // string length 
#define sz(x)     ((ll)(x).size())
#define srt(x)    sort(all(x))
#define srtd(x)   sort(x.rbegin(),x.rend())
#define rev(x)    reverse(all(x));
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)
#define lowB(v,x) lower_bound(all(v),x)-v.begin() // >=x
#define upB(v,x)  upper_bound(all(v),x)-v.begin() // > x
#define ers(v,i)  v.erase(v.begin()+i) 
#define uniq(x)   x.erase(unique(all(x)),x.end())
#define NextP(x)  next_permutation(all(x))
#define PrevP(x)  prev_permutation(all(x))
#define cntB(x)   __builtin_popcountll(x)  
#define cntC(s,x) ll(count(all(s), x));

//IO
#define nl      cout<< "\n";
#define ya      cout<<"YES\n";
#define na      cout << "NO\n";
#define inpt(v) fl(i,sz(v)) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << " "; cout << "\n";
#define pr(x)   cout<<x<<endl;

//Constants
const int M = 1e9+7; 
const int N = 2e5+5;
const ld pi = 3.141592653589793238;
const ll INF = 9e18;
//bits
int SetBit (int n, int X) { return n | (1 << X); }
int ClearBit (int n, int X) { return n & ~(1 << X); }
int ToggleBit (int n, int X) { return n ^ (1 << X); }
bool CheckBit (int n, int X) { return (bool)(n & (1 << X));}

bool isPrime(ll x){ if(x<=1) return false; for(ll i=2 ; i*i<=x;  i++){if(x%i==0)return false;}return true;}
ll  power(int a , int b){if(!b) return 1;ll ret=power(a,b/2);return (b & 1 ? ret*ret*a: ret*ret);}
ll binary(ll a, vector<ll>&v){
    ll l=0, r=v.size()-1;
    while(r-l>1){
        ll mid=(l+r)/2;
        if (a>v[mid]){
            l=mid+1;
        }
        else r=mid;
    }
    if (v[r]==a) return r;
    if(v[l]==a) return l;
    else return -1;
}
bool ispalindrome(string s){
    string s1=s;
    reverse(all(s));
    if(s1==s) return true;
    else return false;
}

//modulo exponential
ll moduloexp(ll base,ll exp){
    ll result =1;
    while(exp>0){
        if(exp&1){
            result= (result*base)%M;
        }
        base=(base*base)%M;
        exp>>=1;
    }
    return result;
}
vector<ll> fac,ifac;//fac-factorial,ifac-modulo inv of fac
void precompute(ll n) {
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (ll i = 2; i <= n; i++) {
        fac[i] = (i * fac[i-1] % M);
    }

    ifac.resize(n + 1);
    for (ll i = 0; i < fac.size(); i++) {
        ifac[i] = moduloexp(fac[i], M - 2);
    }
    return;
}
//nCr
ll nCr(ll n, ll r) {
    if ((n < 0) || (r < 0) || (r > n)) {
        return 0;
    }
    return (fac[n] * ifac[r] % M * ifac[n - r] % M);
}
//sieve of eratosthenes
vector<bool> isprime;
void sieveOfEratosthenes(ll n)
{
    isprime.resize(n+1,true);
    isprime[0]=false;
    isprime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(!isprime[i]) continue;
        for(ll j=2*i; j<=n; j+=i){
            isprime[j]=false;
        }
    }
}
ll add(ll a,ll b)
{
    return (a%M + b%M)%M;
}
ll multi(ll a,ll b)
{
    return ((a%M) *(b%M))%M;
}
ll divide(ll a,ll b)
{
    return ((a%M)*(moduloexp(b,M-2)%M))%M;
}

///8 d -->movement in a grid 
vector<pair<ll,ll>> movements={
    {1,1},{-1,1},{-1,-1},{1,-1},
    {1,0},{0,1},{-1,0},{0,-1},
};

ll n,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
str s,s1,s2;
bool f,g;
char d,e;
//----------------------
//Let's Go :)
void solve(){
    cin>>n>>s;
    
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
