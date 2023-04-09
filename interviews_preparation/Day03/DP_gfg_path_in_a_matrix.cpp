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
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        int dp[n+1][n+1] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    dp[i][j] = a[i][j];
                    continue;
                }
                
                dp[i][j] = dp[i-1][j];                  // Move Down
                
                if(j-1 >= 0)                            // Move Diagonally bottom-right
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                    
                if(j+1 < n)                             // Move Diagonally bottom-left
                    dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
                dp[i][j] += a[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans,dp[n-1][i]);
        cout << ans << endl;
    }


	return 0;
}
