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

int greedy(vi a){
	int n = a.size();
	int l = 0, r = n-1;
	int ans = 0, year = 1;
	
	while(l <= r){
		if(a[l] > a[r]){
			ans += a[r--]*year;
		}
		else{
			ans += a[l++]*year;
		}
		year++;
	}
	return ans;
}

int solve(vector<int> a, int l, int r){
	if(l == r){
		return a[l]*(int)a.size();
	}
	int curYear = (a.size() -  (r-l+1) + 1);
	int beg = a[l]*curYear + solve(a,l+1,r);
	int end = a[r]*curYear + solve(a,l,r-1);
	
	return max(beg,end);
}

int topDown(vector<int> a,int l,int r, int dp[][1000]){
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	
	if(l == r){
		return dp[l][r] = a[l]*(int)a.size();
	}
	int curYear = (a.size() -  (r-l+1) + 1);
	int beg = a[l]*curYear + topDown(a,l+1,r,dp);
	int end = a[r]*curYear + topDown(a,l,r-1,dp);
	
	return dp[l][r] = max(beg,end);
}


int32_t main(){
	vector<int> a = {2, 3, 5, 1, 4};
	int n = a.size();
	
	cout << "Greedy = " << greedy(a) << endl;		// Wrong
	
	cout << "Recursive = " << solve(a,0,n-1) << endl;	// recursive - exponential Solution
	
	// Optimised DP Solution
	
	// Top down
	int dp[a.size()][1000];
	memset(dp,-1,sizeof(dp));
	
	cout << "Top Down = " << topDown(a,0,n-1,dp) << endl; 
	memset(dp,-1,sizeof(dp));
	
	
	
	// Bottom Up
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < n; j++){
			if(i > j){
				dp[i][j] = 0;
			}
			else if(i == j){
				dp[i][j] = a[i]*n;
			}
			else{
				dp[i][j] = max(a[i]*(n-(j-i+1)+1) + dp[i+1][j], a[j]*(n-(j-i+1)+1) + dp[i][j-1]);
			}
		}
	}
	
	cout << "Bottom Up = " << dp[0][n-1] << endl;
	
	

	return 0;
}
