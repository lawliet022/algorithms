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
        // One way to find min insertion to make palindrome is n - lcs(S,Srev)
        // Other using DP
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int dp[n+1][n+1] = {0};
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(i == j){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                    }
                }
            }
        }
        int len = dp[0][n-1];
        
        if(len > k){
            cout << "NO\n";
        }
        else{
			cout << "YES\n";
        }
    }


	return 0;
}
