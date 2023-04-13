
2nd problem : 1811 E : (recursion + memoization + binary search + single digit restriction )
3rd problem below : 1808 C (best recursion + memoization + binary search + digits bounds)

1. Problem : 
/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
int DP[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> a >> b >> d >> k;
    int res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}

2. Problem 1811 E- codeforces

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
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

vl nums;
void update(ll n)
{
    vl ans;
    while(n>0)
    {
        ans.push_back(n%10);n/=10;
    }
    reverse(all(ans));
    nums=ans;
}
vector dp(20,vector(2,vector<ll> (2,-1)));
ll func(ll pos, ll  f , ll g)
{
    if(pos>nums.size()) return 0;
    if(pos == nums.size())
    {
        if(g) return 1;
        else return 0;
    }

    if(dp[pos][f][g]!=-1) return dp[pos][f][g];
    ll ans=0;
    ll options;
    if(f==0)
    {
        options=nums[pos];
    }
    else options=9;
    for(ll dgt=0;dgt<=options;dgt++)
    {
        ll ff=f,gg=g;
        if(dgt==4) gg=1;
        if(f==0 and dgt<options) ff=1;
        ans+=func(pos+1,ff,gg);
    }
    return dp[pos][f][g]=ans;
}
// void renew()
// {
//     dp.assign(20,vector(2,vector<ll>(2,-1)));
// }
void solve()
{
    //START
    cin>>n;
    // renew();
    l=n;r=1e14;
    ans=0;
    // return;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        // renew();
        update(mid);
        for(int i=0;i<nums.size();i++) for(ll j=0;j<2;j++) for(ll k=0;k<2;k++){dp[i][j][k]=-1;}
        // dbg(mid);
        ll diff = (mid-n)-func(0,0,0);
        // dbg(diff);
        if(diff>=0)
        {
            ans=mid;r=mid-1;
        }
        else l=mid+1;
    }
    pr(ans);
    // nums=digits(n);
    // ll diff=func(0,0,0);
    // ll a=diff;
    // // dbg(a);
    // while(diff>0)
    // {
    //     dp.assign(20,vector(2,vector<ll>(2,-1)));
    //     n=n+diff;
    //     // dbg(n);
    //     nums=digits(n);
    //     ll temp=func(0,0,0);
    //     diff=(temp-a);
    //     // dbg(diff);
    //     a=temp;
    // }
    // // dbg(a);
    // pr(n);
    //END
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

/*__builtin_popcountll(x) ,ref-bg-53960*/

3. CF 1808 C 

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
const ll INF = 9e18;
const ld eps = 1e-20;

ll n,m,k,a,b,c,q,x,y,l,r,ans,ans1,ans2,mx,mn,sum;

vl nums;
void update(ll n)
{
    vl ans;
    while(n>0)
    {
        ans.push_back(n%10);n/=10;
    }
    reverse(all(ans));
    nums=ans;
}
vector dp(20,vector(2,vector(2,vector<ll>(2,-1))));
ll func(ll pos, ll  a , ll b,ll f,ll g,ll h)
{
    if(pos==nums.size()) 
    {
        if(g) return 1;
        else return 0;
    }
    if(dp[pos][f][g][h]!=-1) return dp[pos][f][g][h];
    ll ans=0;
    if(pos==0)
    {
        ans+=func(pos+1,a,b,f,g,1);
    }
    if(h)
    {
        if(g==0) ans+=func(pos+1,a,b,f,g,1);
        for(ll dgt=a;dgt<=b;dgt++)
        {
            ll gg=g;
            if(gg==0 and dgt>0) gg=1;
            ans+=func(pos+1,a,b,f,gg,1);
        }
    }
    else if(f==0)
    {
        for(ll dgt=a;dgt<=min(b,nums[pos]);dgt++)
        {
            ll ff=f;
            if(f==0 and dgt<nums[pos]) ff=1;
            ll gg=g;
            if(gg==0 and dgt>0) gg=1;
            ans += func(pos+1,a,b,ff,gg,h);
        }
    }
    else
    {
        for(ll dgt=a;dgt<=b;dgt++)
        {
            ll gg=g;
            if(gg==0 and dgt>0) gg=1;
            ans+=func(pos+1,a,b,f,gg,h);
        }
    }
    return dp[pos][f][g][h]=ans;
}
void renew()
{
    dp.assign(nums.size(),vector(2,vector(2,vector<ll>(2,-1))));
}
void solve()
{
    //START
    cin>>l>>r;
    ans=l;
    if(l==r)
    {
        pr(l);
        return;
    }
    for(ll d=0;d<=9;d++)
    {
        for(ll i=0;i<=9-d;i++)
        {
            ll j=i+d;
            update(r);
            renew();
            ll a1=func(0,i,j,0,0,0);
            ll a2=0;
            if(l!=1) update(l-1);
            renew();
            if(l!=1) a2=func(0,i,j,0,0,0);
            // continue;
            if(a1>a2)
            {
                // dbg(i);
                // dbg(j);
                // dbg(a1);
                // dbg(a2);
                ll l1=l,r1=r+1;
                while(l1<=r1)
                {
                    ll mid=(l1+r1)/2;
                    update(mid);
                    renew();
                    a1=func(0,i,j,0,0,0);
                    if(l1!=1) update(l1-1);
                    renew();
                    a2=0;
                    if(l1!=1) a2=func(0,i,j,0,0,0);
                    if(a1>a2)
                    {
                        ans=mid;r1=mid-1;
                    }
                    else l1=mid+1;
                }
                pr(ans);
                return;
            }
        }
    }
    pr(ans);
    //END
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

/*__builtin_popcountll(x) ,ref-bg-53960*/


