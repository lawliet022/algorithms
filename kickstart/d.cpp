#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void __print(int x) {cerr << x;}
void __print(int32_t x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << "'" << x << "'";}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HELLO
#define error(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define error(x...)
#endif


int dp[15][2][120][120];

int init;

int rec(int pos, vector<int> &v, int small, int sumi, int rem) {
	if (rem < 0) return 0;
	if (pos == (int)v.size()) {
		return (sumi == 1 && rem == 0);
	}
	if (dp[pos][small][sumi][rem] != -1) return dp[pos][small][sumi][rem];
	int maxi;
	if (small) maxi = 9;
	else maxi = v[pos];
	int ans = 0;
	for (int i = 0; i <= min(rem, maxi); i++) {
		if (small)
			ans += rec(pos + 1, v, small, (i == 0 && rem != init ? 1 : sumi / __gcd(sumi, max(1LL, i))), rem - i);
		else
			ans += rec(pos + 1, v, i < maxi, (i == 0 && rem != init ? 1 : sumi / __gcd(sumi, max(1LL, i))), rem - i);
	}
	return dp[pos][small][sumi][rem] = ans;
}

int go(int n, int sumi) {
	int m = n;
	vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	reverse(v.begin(), v.end());
	// error(m, v, sumi);
	memset(dp, -1, sizeof dp);
	init = sumi;
	int res = rec(0, v, 0, sumi, sumi);
	// error(res);
	return res;
}

void solve(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	// TODO(change)!!!!!!!!
	for (int i = 1; i <= 9 * 11; i++) {
		int x =  go(b, i);
		int y = go(a - 1, i);
		// error("sum", i, x, y);
		ans += x - y;
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		#ifndef HELLO
			cout << "Case #" << tt << ": ";
		#endif 
		solve();
	}
	
	return 0;
}