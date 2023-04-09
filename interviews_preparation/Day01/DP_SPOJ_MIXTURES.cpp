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


const int INF = 1e9;

int solve(int a[], int b[], int l, int r, int n){
	if(l >= r){
		return 0;
	}
	//cout << l << " " << r << endl;
	int ans = INF;
	for(int i = l; i < r; i++){
		ans = min(ans,solve(a,b,l,i,n) + solve(a,b,i+1,r,n) + ((l ? b[i] - b[l-1] : b[i]) % 100) * ((b[r] - b[i]) % 100));
	}
	return ans;
}




int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	while(cin >> n){
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int b[n];
		b[0] = a[0];
		for(int i = 1; i < n; i++){
			b[i] = (b[i-1] + a[i]);
		}
		//cout << solve(a,b,0,n-1,n) << endl;			// Recursive - (Exponential Solution)
		
		// DP solution
		int dp[n+1][n+1];
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				dp[i][j] = 0;
			}
		}
		for(int i = n-1; i >= 0; i--){
			for(int j = i; j < n; j++){
				if(i == j){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = INF;
					for(int k = i; k < j; k++){
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + ((i ? b[k] - b[i-1] : b[k]) % 100) * ((b[j] - b[k]) % 100) );
					}
				}
			} 
		}
		cout << dp[0][n-1] << endl;
		
	}

	return 0;
}

