This is how to solve digit dp problems using Combinatronics and binary search concept

Ref - Cf blog post - https://codeforces.com/blog/entry/114520

Problem 1. Cf problem - 1808 C (unlucky numbers)


#include "bits/stdc++.h"
using namespace std;

using i64 = long long;
#define int i64

vector <int> digits(int n) {
	vector<int> ans;
	while(n) {
		ans.push_back(n % 10);
		n /= 10;
	}
	reverse(begin(ans), end(ans));
	return ans;
}

int binexp(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res *= a;
        a = (a * a);
        b >>= 1;
    }
    return res;
}

int count(int n, int a, int b) {
	if(n == 0) {
		return a == 0;
	}
	int res = 0;
	// choice from [a..b] 
	int options = b - a + 1;

	vector <int> d = digits(n); 
	int l = d.size();

	bool self = true;
	for(int i = 0; i < l; i++) {
		// if d[i] < a then we cannot choose any digit from [a..b]
		if(d[i] < a) {
			self = false;
			break;
		}
		int rem = l - i - 1;
		for(int j = a; j <= min(b, d[i] - 1); j++) {
			// if we choose all digits smaller than d[i], we can select the remaining digits as per our choice 
			res += binexp(options, rem);
		}
		// if d[i] > b then we cannot proceed further using this digit 
		if(d[i] > b) {
			self = false;
			break;
		}
	}	

	if(a != 0 and l > 1)
		if(options > 1)
			res += options * (binexp(options, l - 1) - 1) / (options - 1);
		else res += l - 1;

	if(self) res++;
	return res;
}

int netCount(int n, int a, int b) {
    // we need to make sure we have atleast one digit a, and another digit b
	int res = count(n, a, b);
	if(a != b) {
		res -= count(n, a + 1, b);
		res -= count(n, a, b - 1);
		if(a + 1 <= b - 1) {
			res += count(n, a + 1, b - 1);
		}
	}
	return res;
}

bool get(int l, int r, int a, int b) {
	return netCount(r, a, b) - netCount(l - 1, a, b) > 0;
}

void solve() {
	
	int l, r; cin >> l >> r;
	int a = 0, b = 9, diff = 9;
	for(int d = 0; d <= 9; d++) {
		bool got = false;
		for(int i = 0; i <= 9 - d; i++) {
			int j = i + d; 
			if(get(l, r, i, j)) {
				a = i, b = j;
				diff = d;
				got = true;
				break;
			}
		}
		if(got) break;
	}
	// lets do binary search to find any such integer with smallest digit a and largest digit b and diff = b - a
	int lo = l, mid, hi = r;
	int ans = r;
	while(lo <= hi) {
        mid = (lo + hi) / 2;
		if(get(l, mid, a, b) ) {
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	cout << ans << '\n';

}

int32_t main() {
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
    while(t--) solve();
}

2. Problem 2 : 1811 E 


#include <bits/stdc++.h>
using namespace std;

#ifdef MYPC
  #include "debugger.h"
#else 
  #define debug(...) 
  #define debugcase(x)
#endif 

using i64 = long long;
#define int i64
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define all(x) x.begin(), x.end() 
#define rall(x) x.rbegin(), x.rend() 
#define LOOP(i, x, y) for(int i = (x); i <= (y); i++)
#define FOR(i, n) LOOP(i, 0, n - 1)
#define REV(i, x, y) for(int i = (x); i >= (y); i--)
#define yesno(x) (x ? "YES" : "NO")
template<typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for(auto& x : v) in >> x;
  return in;
}

int binexp(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res *= a;
    a = (a * a);
    b >>= 1;
  }
  return res;
}

vector <int> digits(int n) {
  vector <int> res;
  while (n) {
    res.push_back(n % 10);
    n /= 10;
  }
  reverse(begin(res), end(res));
  return res;
} 

int count(int n, int k) {
  // debug(n);
  // doesnt contain the digit k for k >= 1 and k <= 9
  int options = 9;
  int res = 0;
  auto d = digits(n);
  int sz = d.size();
  
  bool self = true;
  for(int i = 0; i < sz; i++) {
    // debug(i, res);
    int rem = sz - i - 1;
    // choose digit smaller than d[i] and we can select numbers according to our choice
    for(int j = (i == 0); j <= d[i] - 1; j++) {
      if(j == k) continue;
      res += binexp(options, rem);
    }
    // explore for more options keeping digit d[i] fixed
    if(d[i] == k) {
      self = false;
      break;
    }
  }

  if (sz > 1) {  
    res += binexp(options, sz - 1) - 1;
  }
  // debug(res);
  if(self) res++;
  return res;
}

int get(int k) {
  int lo = 1, mid, hi = 1e18;
  int ans = -1;
  while(lo <= hi) {
    mid = (lo + hi) >> 1;
    int cnt = count(mid, 4);
    if(cnt >= k) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
void solve() {
  int k; cin >> k;
  cout << get(k) << "\n";
}

int32_t main() {
  // checks();
  cin.tie(0) -> sync_with_stdio(0);
  int TC = 1; 
  cin>>TC;
  FOR(t, TC) {
    solve();
  }
    
}
