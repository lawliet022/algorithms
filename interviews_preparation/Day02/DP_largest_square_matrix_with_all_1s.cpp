#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        
        int above[n+1][m+1] = {0};
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0 || a[j-1][i-1] == 0){
                    above[j][i] = 0;
                    continue;
                }
                above[j][i] += above[j-1][i] + 1;
            }
        }
        
        
        int dp[n+1][m+1] = {0};
        for(int i = 0; i <= n; i++){
            int prev = 0;
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0 || a[i-1][j-1] == 0){
                    dp[i][j] = 0;
                    prev = 0;
                    continue;
                }
                prev++;
                if(dp[i-1][j-1] == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min({prev,above[i][j],dp[i-1][j-1]+1});
                }
                
            }
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++)
                ans = max(ans,dp[i][j]);
        }
        cout << ans << endl;
    }
    


	return 0;
}
