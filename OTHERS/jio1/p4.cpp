#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		double vol;
		cin >> n >> vol;
		double a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		double l = 0, r = 1e15 + 100;
		int iter = 250;
		double ans = 0;
		while(iter--){
			double mid = (l + r) / 2.0;
			double val = 0;
			for(int i = 0; i < n; i++){
				val += (a[i] + mid) * (a[i] + mid) * (a[i] + mid);
			}
			if(val <= vol){
				ans = mid;
				l = mid;
			}
			else{
				r = mid;
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
		
	}
	
	return 0;
}
