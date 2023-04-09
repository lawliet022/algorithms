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

const int MAX = 1e3;

int dp2[MAX][2];

int solve(int a[], int i, int type){
	if(i == 0)
		return 0;

	int &ans = dp2[i][type];
	
	if(ans != -1)
		return ans;
		
	if(type == 0){
		int x = solve(a,i-1,type);							// 1->1
		int y = a[i-1] - 1 + solve(a,i-1,1-type);			// MAX->1
		return ans = max(x,y);
	}
	else{
		int x = abs(a[i]-a[i-1]) + solve(a,i-1,type);		// MAX->MAX
		int y = a[i] - 1 + solve(a,i-1,1-type);				// 1->MAX
		return ans = max(x,y);
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int dp[2][n+1] = {0};
        dp[0][0] = 0;
        dp[1][0] = 0;
        
        for(int i = 1; i < n; i++){
            dp[0][i] = dp[0][i-1];      // 1 -> 1    
            dp[0][i] = max(dp[0][i], dp[1][i-1] + a[i-1]-1);     // MAX -> 1
            
            dp[1][i] = dp[0][i-1] + a[i]-1 ;     // 1 -> MAX    
            dp[1][i] = max(dp[1][i], dp[1][i-1] + abs(a[i-1]-a[i]));     // MAX -> MAX
            
            
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << endl;
        
        // Top down
        memset(dp2,-1,sizeof dp2);
        cout << max(solve(a,n-1,0),solve(a,n-1,1)) << endl;
        
        
    }


	return 0;
}
