#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


void solve(){
	int n, b;
	cin >> n >> b;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int l = 0, r = 0;
	int cur = 0, ans = 0;
	while(r < n){
		cur += a[r++];
		while(cur > b){
			cur -= a[l++];
		}
		ans = max(ans,cur);
	}
	ans = max(ans,cur);
	cout << ans << endl;
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
