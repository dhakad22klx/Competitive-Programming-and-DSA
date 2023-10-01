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

//KMP algorithm 

//cp algo: https://cp-algorithms.com/string/prefix-function.html 
//YT : https://www.youtube.com/watch?v=XOMePGIVJZA&list=PL5DyztRVgtRWVqLox_K8lrWZCclxzHzLD&index=8

/*You are given a string 's' of length.The prefix function for this string 's' is defined as 
an array 'pi' of length 'n' where pi[i] is the length of the longest proper prefix of the substring 
s[0....i] which is also a suffix of this substring. A proper prefix of a string is a prefix that is not equal to the string itself. By definition,
pi[0] = 0.*/
vector<ll> prefix_function(string &s) 
{
    ll n = s.length();
    vector<ll> pi(n);
    for(ll i = 1; i < n; i++) {
        ll j = pi[i-1];
        while(j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}
//Time complexity : O(n)
/////////////////////////|| जय श्री राम ||//////////////////////
void solve()
{
    //START
    //problem name : Password codeforces
    //https://codeforces.com/problemset/problem/126/B
    string s;
    cin>>s;
    vector<ll> pre = prefix_function(s);//string hash function
    ll n = pre.size();
    x=pre[n-1];
    if(x==0)
    {
        cout<<"Just a legend";nl;return;
    }
    for(ll i=0;i<n-1;i++)//n-1 coz searching if there is any substring in middle
    {
        if(pre[i]==x)
        {
            string ans = s.substr(0,x);
            cout<<ans;nl;return;
        }
    }
    x=pre[x-1];
    if(x==0)
    {
        cout<<"Just a legend";nl;return;
    }
    string ans = s.substr(0,x);
    cout<<ans;nl;return;
    //END
}
/////////////////////////|| जय महाकाल ||//////////////////////
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
