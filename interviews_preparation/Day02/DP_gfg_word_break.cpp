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


	
bool solve(string s, int ind){
	if(ind == (int)s.size())
		return 1;
	for(int i = ind; i < (int)s.size(); i++){
		if(m.count(s.substr(ind,i-ind+1)) && solve(s,i+1))
			return 1;
	}
	return 0;
}


int32_t main(){
	vector<string> dict = {"mobile","samsung","sam","sung", 
                            "man","mango","icecream","and", 
                             "go","i","like","ice","cream","end"};
	for(auto x: dict)
		m[x] = 1;
	
	string s = "ilikeendend";
	
	cout << solve(s,0) << endl; 		// Recursive Approach
	
	
	// DP
	int n = s.size();
	int dp[n+1] = {0};
	
	int flag = 0;
	
	for(int i = 1; i <= n; i++){
		if(m.count(s.substr(0,i)))
			dp[i] = 1;
		if(dp[i]){
			if(i == n){
				cout << "Found\n";
				flag = 1;
				break;
			}
			for(int j = i+1; j <= n; j++){
				if(dp[j] == 0 && m.count(s.substr(i,j-i)))
					dp[j] = 1;
			}
			if(dp[n-1]){
				cout << "found\n";
				flag = 1;
				break;
			}
		}
	}
	if(!flag){
		cout << "Not found\n";
	}
	
	
	// DP optimised (Rather than finding )
	
	
	
	return 0;
}

