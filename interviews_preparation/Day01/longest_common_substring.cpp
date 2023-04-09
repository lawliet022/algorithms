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
	string a = "geekforgeeks", b = "forkgeeks";
	int n = a.size(), m = b.size();
	int ans = 0;
	int dp[n+1][m+1];
	memset(dp,0,sizeof dp);
	int index = -1;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			else{
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
					if(ans < dp[i][j]){
						ans = dp[i][j];
						index = i-ans;
					}
					// ans = max(ans,dp[i][j]);				// Use it if only want length
				}
				else
					dp[i][j] = 0;
			}
		}
	}
	if(index != -1)
		cout << "Max common substring = " << a.substr(index,ans) 
			<< "\nlength = " << ans<<endl;
	else
		cout << "Nothing in common\n";


	return 0;
}

