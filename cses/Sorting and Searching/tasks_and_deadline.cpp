#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end());
	
	int cur = 0, ans = 0;
	for(int i = 0; i < n; i++){
		cur += v[i].first;
		ans += v[i].second - cur;
	}
	cout << ans << endl;
	
	return 0;
}
