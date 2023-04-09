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
	int n;
	cin >> n;
	
	int dp[2][3];
	for(int i = 0; i < 3; i++)
		cin >> dp[0][i];
	
	for(int i = 1; i < n; i++){
		int a[3];
		for(int j = 0; j < 3; j++)
			cin >> a[j];
		for(int j = 0; j < 3; j++){
			dp[1][j] = 0;
			for(int k = 0; k < 3; k++){
				if(j == k)
					continue;
				dp[1][j] = max(dp[1][j],dp[0][k] + a[j]);
			}
		}
		for(int j = 0; j < 3; j++){
			dp[0][j] = dp[1][j];
		}
	}
	cout << max({dp[0][0],dp[0][1],dp[0][2]}) << endl;

	return 0;
}

