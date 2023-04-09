#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

// This approach is better than all subset approach.
// Time complexity is O(n*m)	- where m is max possilbe xor value
// In this case m is less than 300 as max ai = 100

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n+1][300];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 300; j++)
                dp[i][j] = 0;
        }
        dp[0][0] = 1;
        for(int i = 1;i <= n; i++){
            for(int j = 0; j < 300; j++){
                dp[i][j] = dp[i-1][j] + dp[i-1][j^a[i-1]];
            }
        }
        cout << dp[n][k] << endl;
    }
    


	return 0;
}
