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
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	const int INF = 1e9 + 10;
	vector<int> dp(n,INF);
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		for(int j = i-1; j >= max(0LL,i-k); j--){
			dp[i] = min(dp[i],dp[j] + abs(a[i]-a[j]));
		}
	}
	cout << dp[n-1] << endl;

	return 0;
}

