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

//Z-function :preprocessing

/* 1. Suppose we are given a string 's' of length 'n'.
The Z-function for this string is an array of length 'n' where the 'i'th element is equal to 
the greatest number of characters starting from the position 'i' 
that coincide with the first characters of 's'.*/

/* 2. In other words,z[i] is the length of the longest string that is, at the same time,
a prefix of 's' and a prefix of the suffix of 's' starting at 'i'.*/


//Refer cp algo : https://cp-algorithms.com/string/z-function.html
//CP handbook 

vector<ll> z_function(string &s) 
{
    ll n=s.length();
    vl z(n);
    // [l...r] --> rightmost segment match
    int l = 0, r = 0;
    for(ll i = 1; i < n; ++i)
    {
        if (i < r)
        {
            z[i] = min(r - i , z[i - l]);
        }
        while (i + z[i] < n and s[i + z[i]] == s[z[i]])
        {
            z[i]++;
        }
        //Update --rightmost segment match
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

//Linear Time Complexity 
/////////////////////////|| जय श्री राम ||//////////////////////
void solve()
{
    //START
    //Problem : password : codeforces
    //https://codeforces.com/problemset/problem/126/B
    string s;
    cin>>s;
    vl z = z_function(s);
    ll n = s.length();
    string ans = "Just a legend";
    set<ll> st;
    mx = -1;
    for(ll i=1;i<n;i++)
    {
        if(z[i]>0) 
        {
            auto it = st.lower_bound(z[i]);
            if(it!=st.end()) mx = max(mx,z[i]); 
        }
        if(z[i]>0) st.insert(z[i]);
    }
    if(mx!=-1) ans = s.substr(0,mx);
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
