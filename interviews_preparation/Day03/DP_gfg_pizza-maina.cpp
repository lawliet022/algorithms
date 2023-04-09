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
        int req, s, m, l, cs, cm, cl;
        cin >> req >> s >> m >> l >> cs >> cm >> cl;
        
        int dp[req+l+1];
        const int INF = 1e9;
        for(int i = 1; i <= req+l; i++)
			dp[i] = INF;	
        dp[0] = 0;
        
        for(int i = 0; i <= req; i++){
            if(i+s <= req+l && dp[i] != INF){
                dp[i+s] = min(dp[i+s],dp[i] + cs);
            }
        }
        
        for(int i = 0; i <= req; i++){
            if(i+m <= req+l && dp[i] != INF){
                dp[i+m] = min(dp[i+m],dp[i] + cm);
            }
        }
        
        for(int i = 0; i <= req; i++){
            if(i+l <= req+l && dp[i] != INF){
                dp[i+l] = min(dp[i+l],dp[i] + cl);
            }
        }
        
        //for(int i = 0; i < req+l+1; i++)
			//cout << dp[i] << " ";
		//cout << endl;
		
        int ans = INF;
        for(int i = req; i <= req+l; i++)
            ans = min(ans,dp[i]);
        cout << ans << endl;
    }


	return 0;
}
