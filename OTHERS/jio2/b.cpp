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
		int n, c, k;
		cin >> n >> c >> k;
		vector<int> a;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		int l = 0, r = 0, ans = 0, cur_sum = 0;
		while(r < n){
			cur_sum += a[r];
			r++;
			while(cur_sum > c){
				cur_sum -= a[l];
				l++;
			}
			if(cur_sum >= k && cur_sum <= c){
				ans = max(ans,r-l);
			}
			while(r < n && cur_sum + a[r] <= c){
				cur_sum += a[r];
				r++;
				if(cur_sum >= k && cur_sum <= c){
					ans = max(ans,r-l);
				}
			}
		}
		if(cur_sum >= k && cur_sum <= c){
			ans = max(ans,r-l);
		}
		cout << ans << endl;
		
	}
	
	return 0;
}
