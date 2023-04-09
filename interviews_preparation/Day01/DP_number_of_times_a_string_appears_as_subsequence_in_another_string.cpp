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

map<pair<int,int>,int> s;

int countOccurances(string a, string b, int m, int n){
	if(m == 0){
		if(n != 0)
			return 0;
		else
			return 1;
	}
	if(n == 0)
		return 1;
	if(a[m-1] == b[n-1]){
		return countOccurances(a,b,m-1,n-1) + countOccurances(a,b,m-1,n);
	}
	else
		return countOccurances(a,b,m-1,n);
}


int32_t main(){
	string a = "GeeksforGeeks";
	string b = "Gks";
	
	// Recursive approach - overlapping subproblems (Exponential solution)
	
	cout << countOccurances(a,b,a.size(),b.size()) << endl;
	
	// DP Approach - O(mn) 
	int dp[a.size()+1][b.size()+1] = {0};
	
	// First string is empty
	for(int i = 0; i <= (int)b.size(); i++)
		dp[0][i] = 0;
	
	// Second string is empty
	for(int i = 0; i <= (int)a.size(); i++)
		dp[i][0] = 1;
	
	for(int i = 1; i <= (int)a.size(); i++){
		for(int j = 1; j <= (int)b.size(); j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];		
		}
	}
	cout << dp[a.size()][b.size()];

	return 0;
}

