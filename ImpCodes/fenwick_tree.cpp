Question : 1. https://cses.fi/problemset/task/1646
           2. https://codeforces.com/problemset/problem/102/D


A Fenwick Tree answers prefix sum queries and point updates in O(log n) time. 
The magic lies in how it uses the lowest set bit (LSB) of an index to decide what range each node stores.
//Cp algorithm for tutorials 
A fenwick tree can support 
1. Point Update and Range Query
2. Range Update and Point Query //using difference array 
3. Range Update and Range Query 

//Binary lifting code also attached below 


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
#define ff                   first
#define ss                   second
#define pus                  push_back
#define bb                   begin()
#define ee                   end()
#define dbg(x) cout<<#x<<" = "<<x<<'\n';

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
const ld pi = 3.141592653589793238;                                                                               
const ll INF = 9e18;
const ld eps = 1e-6;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn;
vl v;
void add(ll i,ll x)
{
    while(i<=n)
    {
        v[i]+=x;
        i+=(i&-i);
    }
}
ll sum(ll i)// sum from [1,i]
{
    ll result = 0;
    while(i>0)
    {
        result += v[i];
        i-=(i&-i);
    }
    return result;
}
void solve()
{
    //START
    cin>>n;
    vl ref(n+1,0);
    v.assign(n+1,0);//n+1 size vector-1 based index
    for(ll i=1;i<=n;i++)
    {
        cin>>ref[i];
        add(i,ref[i]);// vector 'v' updatd
    }
    prt(v);
    /* we will perform two type of query 
      1.print sum of range (a,b) -
      2.add element x to at index i,or replace v[i]=(v[i]+x);
      our aim is to perform these query in Log(n) using fenwick tree.
      in fenwick tree every index v[i] store sum of range (k-p(k)+1,k);
      p(k) = k&-k ;//p ( k ) denote the largest power of two that divides k .
    */
    //query 1  is nothing but :  
    cin>>a>>b;
    ans = sum(b)- sum(a-1);//indexing will be 1 based ,sum(x) is sum from 1 to x.
    pr(ans);
    // query 2
    ll i;
    cin>>i>>x;
    add(i,x);
    pr(sum(i)-sum(i-1));//printing v[i]
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



//Binary Lifting pseudo code : https://codeforces.com/blog/entry/61364
// This is equivalent to calculating lower_bound on prefix sums array
// LOGN = log(N)

int bit[N]; // BIT array

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	
	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) < N and sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}
