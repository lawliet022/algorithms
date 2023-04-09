#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	int total = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		total += a[i];
	}
	int ans = 1e12;
	for(int i = 1; i < (1<<n); i++){
		int cur_wt = 0;
		for(int j = 0; j < n; j++){
			if(i&(1<<j)){
				cur_wt += a[j];
			}
		}
		ans = min(ans,abs(cur_wt-(total-cur_wt)));
	}
	cout << ans << endl;
	
	
	return 0;
}
