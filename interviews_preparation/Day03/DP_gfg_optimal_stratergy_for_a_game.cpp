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
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int dp[n+1][n+1] = {0};
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = a[i];
                }
                else if(i+1 == j){
                    dp[i][j] = max(a[i],a[j]);
                }
                else{
                    dp[i][j] = max(a[i] + min(dp[i+2][j],dp[i+1][j-1]), 
                                    a[j] + min(dp[i][j-2],dp[i+1][j-1]));
                }
            }
        }
        cout << dp[0][n-1] << endl;
    }


	return 0;
}
