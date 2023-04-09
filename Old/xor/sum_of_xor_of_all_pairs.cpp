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
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n+1][32];
        for(int i = 0; i <= n; i++)
            for(int j = 0; j < 30; j++)
                dp[i][j] = 0;
        for(int j = 0; j < 30; j++){
            for(int i = n-1; i >= 0; i--){
                dp[i][j] = dp[i+1][j] + ((a[i]>>j)&1LL);
            }
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < 30; j++){
                if(a[i]&(1LL<<j)){
                    ans += ((n-i-1) - dp[i+1][j])*(1LL<<j);
                }
                else
                    ans += dp[i+1][j]*(1LL<<j);
            }
        }
        cout << ans << endl;
    }


	return 0;
}
