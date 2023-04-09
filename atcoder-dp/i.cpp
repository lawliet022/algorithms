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


double dp[3002][3002];		// dp[i][j] - prob of j heads in i tosses

int32_t main(){
	int n;
	cin >> n;
	// prob of more heads
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		double p;
		cin >> p;
		for(int j = 0; j <= i; j++){
			if(j == 0){
				dp[i][0] = dp[i-1][0] * (1.0 - p);
			}
			else{
				dp[i][j] = dp[i-1][j] * (1.0 - p) + dp[i-1][j-1] * p;
			}
		}
	}
	double ans = 0.0;
	
	for(int i = (n+1)/2; i <= n; i++)
		ans += dp[n][i];
		
	cout << fixed << setprecision(10) << ans << endl;


	return 0;
}

