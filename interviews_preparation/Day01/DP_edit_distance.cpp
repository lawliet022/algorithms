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

// Lets say converting a -> b

int32_t main(){
	string a = "sunday", b = "saturday";
	int n = a.size(), m = b.size();
	
	int dp[n+1][m+1];
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 && j == 0)
				dp[i][j] = 0;
			else if(i == 0)					
				dp[i][j] = j;					// (first string empty) - Cost of inserting
			else if(j == 0)
				dp[i][j] = i;					// (second string empty) - Cost of deleting
			else{
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1];
				}
				else 	
					dp[i][j] = 1 + min({dp[i-1][j],				// deleting a char from 'a'
										dp[i][j-1],				// inserting a char in 'a'
										dp[i-1][j-1]});			// replacing a char in 'a'
			}
		}
	}
	cout << dp[n][m] << endl;
	
	

	return 0;
}

