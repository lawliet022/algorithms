#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);



int32_t main(){
	int n;
	cin >> n;
	int ans = n % MOD;
	int cur = 2;
	while(cur <= n){
		int divi = n / cur;
		int l = cur, r = n, p = l;
		while(l <= r){
			int mid = (l + r) / 2;
			if(n / mid == divi){
				p = mid;
				l = mid + 1;
			}
			else{
				r = mid-1;
			}
		}
		int m = p - cur + 1;
		int val = ((m % MOD) * ((2 * cur % MOD + (m - 1))% MOD) % MOD) * 500000004 % MOD;		
		ans += divi * val % MOD;
		ans %= MOD;
		if(ans < 0)
			ans += MOD;
		cur = p + 1;
	}
	cout << ans << endl;
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 	
	
	return 0;
}
