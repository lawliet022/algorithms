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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		int dp[n+1][n+1];
		const int INF = 1e9;
		
		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j < n-1; j++){
				if(i >= j){
					dp[i][j] = 0;
				}
				else if(j-i == 1){
					dp[i][j] = a[i]*a[i+1]*a[i+2];
				}
				else{
					dp[i][j] = INF;
					for(int k = i; k < j; k++){
						dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + a[i]*a[k+1]*a[j+1]);
					}
				}
			}
		}
		//for(int i = 0; i < n-1; i++){
			//for(int j = 0; j < n-1; j++)
				//cout << dp[i][j] << " ";
			//cout << endl;
		//}
		cout << dp[0][n-2] << endl;
	}

	return 0;
}

