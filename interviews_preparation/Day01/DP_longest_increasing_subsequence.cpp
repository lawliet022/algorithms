#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	vector<int> a = {1, 4, 12, 2, 100, 6, 10, 11};
	int n = a.size();
	
	// O(n^2) Approach - can also find subsequence
	int dp[n+1] = {0};
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans,dp[i]);
	}
	cout << ans << endl;
	
	// Printing the subsequence
	int lastVal = 1e9, cnt = ans;
	
	vector<int> res;
	for(int i = n-1; i >= 0; i--){
		if(dp[i] == cnt && lastVal > a[i]){
			res.PB(a[i]);
			cnt--;
			lastVal = a[i];
			if(cnt == 0)
				break;
		}
	}
	reverse(res.begin(),res.end());
	cout << "LIS is ";
	for(auto x : res){
		cout << x << " -> ";
	}
	cout << endl;
	
	// Printing all LIS - Maybe sometime later
	
	
	// O(nlogn) - To find length of LIS
	
	vector<int> v;
	v.PB(a[0]);

	for(int i = 1; i < n; i++){
		if(a[i] > v.back()){
			v.PB(a[i]);
		}
		else{
			int p = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
			v[p] = a[i];
		}
	}
	
	cout << "Length of LIS = " << v.size() << endl;

	return 0;
}

