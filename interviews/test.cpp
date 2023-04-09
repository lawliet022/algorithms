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
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	bool dp[n+1][n+1];
	for(int i = n-1; i >= 0; i--){
		for(int j = i; j < n; j++){
			if(i == j){
				dp[i][j] = 1;
			}
			else if(i+1 == j){
				dp[i][j] = (a[i] == a[j]);
			}
			else{
				dp[i][j] = (dp[i+1][j-1] && (a[i] == a[j]));
			}
		}
	}
	// dp[i] - min number of palindrome sequence till ith pos
	int dp2[n+1];
	dp2[0] = 1;
	
	for(int i = 1; i < n; i++){
		dp2[i] = dp2[i-1]+1;
		for(int j = i-1; j >= 0; j--){
			if(dp[j][i])
				dp2[i] = min(dp2[i],(j-1 >= 0LL? dp2[j-1] : 0LL) + 1);
		}
	}
	//for(int i = 0; i < n; i++)
		//cout << dp2[i] << " ";
	//cout << endl;
	
	cout << dp2[n-1] << endl;

	return 0;
}

