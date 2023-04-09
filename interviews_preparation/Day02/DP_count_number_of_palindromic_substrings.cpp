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
        string s;
        cin >> s;
        int dp[n+1][n+1] = {0};				// To store if a given range is palindrome or not
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
            
        int ans[n+1] = {0};
        for(int i = 1; i < n; i++){
            ans[i] = 0;
            for(int j = i-2; j >= 0; j-=2){      // Odd length
                if(dp[j+1][i-1] && s[i] == s[j]){
                    dp[j][i] = 1;
                    ans[i]++;
                }
            }
            if(s[i-1] == s[i]){
                ans[i]++;
                dp[i-1][i] = 1;
            }
            for(int j = i-3; j >= 0; j-=2){      // Even length
                if(dp[j+1][i-1] && s[i] == s[j]){
                    dp[j][i] = 1;
                    ans[i]++;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += ans[i];
		}
        cout << res << endl;
    }
    


	return 0;
}
