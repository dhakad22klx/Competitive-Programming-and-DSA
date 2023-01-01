//typing 

#include<bits/stdc++.h>
using namespace std;

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
#define fix(n,k) (n%k+k)%k

#define dbg(x) cout<<#x<<" = "<<x<<'\n';

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpl;
typedef vector<vector<ll>> matrix;
typedef pair<ll, ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll>   mll;


//Algorithms
#define sl(k,s)   ll k=s.length(); // string length 
#define sz(x)     ((ll)(x).size())
#define srt(x)    sort(all(x))
#define srtd(x)   sort(x.rbegin(),x.rend())
#define rev(x)    reverse(all(x));
#define Vmax(x)   *max_element(all(x))
#define Vmin(x)   *min_element(all(x))
#define Vsum(x)   accumulate(all(x),0ll)
#define lowB(v,x) *lower_bound(all(v),x) // >=x
#define upB(v,x)  upper_bound(all(v),x)-v.begin() // > x
#define ers(v,i)  v.erase(v.begin()+i) 
#define uniq(x)   x.erase(unique(all(x)),x.end())
#define NextP(x)  next_permutation(all(x))
#define PrevP(x)  prev_permutation(all(x))
#define cntB(x)   __builtin_popcountll(x)  
#define cntC(s,x) ll(count(all(s), x));

//IO
#define nl      cout << "\n";
#define ya      cout << "YES\n";
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
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }

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

///8 d -->movement in a grid 
vector<pair<ll,ll>> movements={
    {1,1},{-1,1},{-1,-1},{1,-1},
    {1,0},{0,1},{-1,0},{0,-1},
};


ll n,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;
str s,s1,s2;
bool f,g;
char d,e;
//---------------------------------------------------------------------------------------------------------------------------------
//Let's Go :)
void solve(){
    return;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}













