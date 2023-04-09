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

int LCS(string a,string b, int n, int m){
	if(n == 0 || m == 0){
		return 0;
	}
	else{
		int ans = 0;
		if(a[n-1] == b[m-1]){
			ans = 1 + LCS(a,b,n-1,m-1);
		}
		else{
			ans = max(LCS(a,b,n-1,m), LCS(a,b,n,m-1));
		}
		return ans;
	}
}

int32_t main(){
	string a = "ABCDGHIPQ", b = "AEDFHRIRAQ";
	int n = a.size(), m = b.size();
	
	
	cout << LCS(a,b,n,m) << endl;
	
	int dp[n+1][m+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++)
			dp[i][j] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m] << endl;
	
	// Printing LCS
	string s = "";
	int l = n, r = m;
	while(l > 0 && r > 0){
		if(a[l-1] == b[r-1]){
			s += a[l-1];
			l--; r--;
		}
		else if(dp[l-1][r] > dp[l][r-1]){
			l--;
		}
		else
			r--;
	}
	reverse(s.begin(),s.end());
	cout << s << endl;

	return 0;
}

