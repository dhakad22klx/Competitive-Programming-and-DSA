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


ll  n,k,a, b,c; str s,t;
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













