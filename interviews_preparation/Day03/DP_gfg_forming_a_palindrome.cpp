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
        string s;
        cin >> s;
        string w = s;
        reverse(w.begin(),w.end());
        int dp[s.size()+1][s.size()+1];
        for(int i = 0; i <= (int)s.size(); i++){
            for(int j = 0; j <= (int)s.size(); j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1] == w[j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        cout << (int)s.size() - dp[s.size()][s.size()] << endl;
    }


	return 0;
}
