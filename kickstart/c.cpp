#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


void solve(){
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = a; i <= b; i++) {
		int prod = 1, sumi = 0, cur = i;
		while (cur) {
			prod *= (cur % 10);
			sumi += (cur % 10);
			cur /= 10;
		}
		if (prod % sumi == 0) {
			cout << i << endl;
			ans++;
		}
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