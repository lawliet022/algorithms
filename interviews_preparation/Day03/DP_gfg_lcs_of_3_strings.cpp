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
        int n, m, k;
        cin >> n >> m >> k;
        
        string a, b, c;
        cin >> a >> b >> c;
        int dp[n+1][m+1][k+1] = {0};
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int p = 0; p <= k; p++){
                    if(i == 0 || j == 0 || p == 0){
                        dp[i][j][p] = 0;
                    }
                    else{
                        if(a[i-1] == b[j-1] && b[j-1] == c[p-1])
                            dp[i][j][p] = dp[i-1][j-1][p-1] + 1;
                        else
                            dp[i][j][p] = max({dp[i-1][j][p], dp[i][j-1][p], dp[i][j][p-1]});
                    }
                }
            }
        }
        cout << dp[n][m][k] << endl;
        
        // Top Down - Maybe sometime later
    }


	return 0;
}
