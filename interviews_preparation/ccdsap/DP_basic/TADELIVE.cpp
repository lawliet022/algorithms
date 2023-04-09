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


// Greedy solves for 100
// Dp for 40

int32_t main(){
	int n, x, y;
	cin >> n >> x >> y;
	
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	
	//int done[n] = {0};
	//int p = x, q = y;
	
	//vector<pii> c(n);
	//for(int i = 0; i < n; i++)
		//c[i] = {a[i] - b[i],i};
	
	//sort(c.begin(),c.end());
	
	//int ans = 0;
	
	//for(int i = n-1; i >= 0; i--){
		//if(p && c[i].F >= 0){
			//ans += a[c[i].S];
			//p--;
			//done[c[i].S] = true;
		//}
		//else
			//break;
	//} 
	//for(int i = 0; i < n; i++){
		//if(q && c[i].F <= 0 && !done[c[i].S]){
			//ans += b[c[i].S];
			//q--;
			//done[c[i].S] = true;
		//}
	//}
	//for(int i = 0; i < n; i++){
		//if(done[c[i].S])
			//continue;
		//if(p && q){
			//if(a[c[i].S] == b[c[i].S]){
				//ans += a[c[i].S];
				//if(p > q)
					//p--;
				//else
					//q--;
			//}
			//else if(a[c[i].S] > b[c[i].S]){
				//ans += a[c[i].S];
				//p--;
			//}
			//else if(a[c[i].S] < b[c[i].S]){
				//ans += b[c[i].S];
				//q--;
			//}
		//}
		//else if(p){
			//ans += a[c[i].S];
			//p--;
		//}
		//else{
			//ans += b[c[i].S];
			//q--;
		//}
	//}
	
	//cout << ans << endl;

	
	// DP
	int dp[n+1][n+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++)
			dp[i][j] = 0;
	}
	
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i && j <= x; j++){
			dp[i][j] = dp[i-1][j-1] + a[i-1];
			
			if(i-j <= y){
				dp[i][j] = max(dp[i][j], dp[i-1][j] + b[i-1]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= x; i++)
		ans = max(ans,dp[n][i]);
	cout << ans << endl;
	

	return 0;
}

