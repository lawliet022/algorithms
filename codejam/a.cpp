#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


void solve(){
	int r, a, b;
	cin >> r >> a >> b;
	int cur = r;
	double ans = 0;
	int step = 1;
	while (cur) {
		ans += PI * cur * cur;
		if (step) cur = cur * a;
		else cur = cur / b;
	}
	cout << fixed << setprecision(10) << ans << endl;
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