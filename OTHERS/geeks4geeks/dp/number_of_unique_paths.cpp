#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int dp[n][m];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				dp[i][j] = 0;
			} 
		}
		dp[0][0] = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == 0 && j == 0)
					continue;
				dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
			} 
		}
		cout << dp[n-1][m-1] << endl;
	}


	return 0;
}
