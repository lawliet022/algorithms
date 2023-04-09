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
	for(auto &x : v){
		cin >> x.first >> x.second;
	}
	sort(v.begin(),v.end(),[&](pair<int,int> &a, pair<int,int> &b){
		if(a.second != b.second)
			return a.second < b.second;
		return a.first < b.first;
	});
	
	int ans = 1;
	int cur = v[0].second;
	for(int i = 1; i < n; i++){
		if(v[i].first >= cur){
			ans++;
			cur = v[i].second;
		}
	}
	cout << ans << endl;
	
	
	return 0;
}
