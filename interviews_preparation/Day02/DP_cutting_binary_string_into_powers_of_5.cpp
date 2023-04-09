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

string getBinary(int n){
    string s = "";
    while(n > 0){
        if(n % 2)
            s += '1';
        else
            s += '0';
        n >>= 1;
    }
    reverse(s.begin(),s.end());
    return s;
}

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    map<int,string> m;
    
    int temp = log(1LL<<50)/log(5);
    int val = 1;
    for(int i = 0; i <= temp; i++){
        m[i] = getBinary(val);
		val *= 5;
    }
    //for(auto x : m){
		//cout << x.F << "-> " << x.S << endl;
	//}
	
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int dp[n+2];
        const int INF = 1e9;
        for(int i = 1; i <= n+1; i++)
            dp[i] = INF;
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= temp; j++){
				if(i-(int)m[j].size() >= 0 && dp[i-m[j].size()] != (int)1e9 && s.substr(i-m[j].size(),m[j].size()) == m[j]){
                    dp[i] = min(dp[i],dp[i-m[j].size()]+1);
                }
            }
        }
        cout << (dp[n] != 1e9 ? dp[n] : -1) << endl;
    }


	return 0;
}
