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
	string s, t;
	cin >> s >> t;
	
	int n = s.size(), m = t.size();
	
	int dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	//cout << dp[n][m] << endl;
	
	string ans = "";
	int l = n, r = m;
	while(l && r){
		if(s[l-1] == t[r-1]){
			ans += s[l-1];
			l--;	r--;
		}
		else if(dp[l][r] == dp[l-1][r]){
			l--;
		}
		else
			r--;
	}
	
	reverse(ans.begin(),ans.end());
	
	cout << ans << endl;

	return 0;
}

