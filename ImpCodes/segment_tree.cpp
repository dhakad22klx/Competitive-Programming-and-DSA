CP Handbook for reference

Note : incase of update query keep note your initial vector is updating i.e. you are considering update 
unlike in fenwick tree we deal with original array but here we deal with another 2*n lenght segment tree array


// general theory
Compared to a binary indexed tree, the advantage of a segment tree is that it
is a more general data structure. While binary indexed trees only support sum
queries, segment trees also support other queries.

Segment trees can support all range queries where it is possible to divide a range
into two parts, calculate the answer separately for both parts and then efficiently
combine the answers. Examples of such queries are minimum and maximum,
greatest common divisor, and bit operations and, or and xor.
//
1. array length should be power of 2 otherwise we append element to make it power of 2.

2. Zero based indexing.

3. We store a segment tree as an array of 2 n elements where n is the size of the original array and a power of two. 
The tree nodes are stored from top to bottom: tree [1] is the top node, tree [2] and tree [3] are its children, and so on.
Finally,the values from tree [ n ] to tree [2 n − 1] correspond to the values of the originalarray on the bottom level of the tree.




//Code starts -basic implementation of sum queries

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
#define ff                   first
#define ss                   second
#define pus                  push_back
#define bb                   begin()
#define ee                   end()
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

ll n;

// sum function to find sum in range of [a,b] -zero based indexing

ll sum(ll a,ll b,vector<ll> &tree)
{
    ll result = 0;
    a+=n,b+=n;//  this 'n' must be power of 2;if given size not power of 2 then manage accordingly 
    while(a<=b)
    {
        if(a%2 == 1) result += tree[a++];
        if(b%2 == 0) result += tree[b--];
        a /= 2;b /= 2;
    }
    return result;
}

// add function to add value 'x' at index k-(zero based) ie. update segment tree

void add(ll k,ll x , vector<ll> &tree )
{
    k+=n;// this 'n' must be power of 2;
    tree[k]+=x;
    for(k/=2;k>=1;k/=2)
    {
        tree[k] = tree[ 2*k ] + tree[ 2*k + 1 ];
    }
}
/////////////////////////||जय श्री राम||//////////////////////
void solve()
{
    //START

    cin>>n;
    vector<ll> v(n);
    inpt(v);//5 8 6 3 2 7 2 6
    //will have to append more element if size is not power of 2 ,n will be updated
    //n-is power of 2
    vector<ll> tree(2*n,0);//2*n size array to store array as segement tree
    for(ll i=0;i<n;i++)
    {
        add(i,v[i],tree);
    }
    // if we update ie. replace value at kth index by 'x'
    //add(k,x-v[k],tree);v[k]=x;//important is making v[k]=x;
    prt(tree);//0 39 22 17 13 9 9 8 5 8 6 3 2 7 2 6 
    pr(sum(0,7,tree));//39 
    pr(sum(5,7,tree));//15
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

