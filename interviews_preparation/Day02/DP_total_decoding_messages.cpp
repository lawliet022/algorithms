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

int dp[50];

int flag = 0;

int solve(string s, int i){
    if(i <= 0){
        return 1;
    }
    if(dp[i] != -1)
        return dp[i];
    
    if(s[i] == '0'){
        if(s[i-1] != '1' && s[i-1] != '2'){
            flag = 1;
		}
        return dp[i] = solve(s,i-2);
    }
    else{
		string temp = "";
		temp += s[i-1];
		temp += s[i];
		if( temp >= "11" && temp <= "26"){
			return dp[i] = solve(s,i-1) + solve(s,i-2);
        }
        else
            return dp[i] = solve(s,i-1);
    }
}


int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        flag = 0;
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        memset(dp,-1,sizeof dp);
        int p = solve(s,n-1);
        cout << (flag ? 0 : p) << endl;
    }


	return 0;
}
