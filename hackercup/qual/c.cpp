#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int>> a(n); 	// {pos,height}
	for(auto &x : a){
		cin >> x.first >> x.second;
	}
	sort(a.begin(),a.end());
	map<int,int> dp;
	for(int i = 0; i < n; i++){
		int p[2] = {0};
		p[0] = (dp.count(a[i].first-a[i].second) ? dp[a[i].first-a[i].second] + a[i].second : a[i].second);
		p[1] = (dp.count(a[i].first) ? dp[a[i].first] + a[i].second : a[i].second);
		dp[a[i].first] = max(dp[a[i].first],p[0]);
		dp[a[i].first+a[i].second] = max(dp[a[i].first+a[i].second],p[1]);
	}
	int ans = 0;
	for(auto x : dp){
		ans = max(ans,x.second);
	}
	cout << ans << endl;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	//freopen("in2.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		cout << "Case #" << test++ << ": ";
		solve();
	}
	
	return 0;
}
