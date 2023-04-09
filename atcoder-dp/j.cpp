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

const int N = 305;
double dp[N][N][N];		// Expected number of tosses to 


int cnt[4] = {0};
int n;

double solve(int a, int b, int c){
	if(a + b + c == 1){
		return n;
	}
	if(a + b + c  == 0){
		return 0;
	}
	if(dp[a][b][c] > -0.5)
		return dp[a][b][c];
	double ans = 0;
	if(c > 0){
		ans += solve(a,b+1,c-1) * 1.0 * c  / n;
	}
	if(b > 0){
		ans += solve(a+1,b-1,c) * 1.0 * b / n;
	}
	if(a > 0){
		ans += solve(a-1,b,c) * 1.0 * a / n;
	}
	//ans += solve(a,b,c) * (n - a - b - c) / n;
	return ans;
}

int32_t main(){
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	memset(dp,-1,sizeof dp);
	
	cout << solve(cnt[1],cnt[2],cnt[3]) << endl;
	

	return 0;
}

