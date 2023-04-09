#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(k >= a[i]){
				ans++;
				k -= a[i];
			}
			else
				break;
		}
		cout << ans << endl;
	}
	
	return 0;
}
