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


// Supersequence is a sequence which contain all given substrings in it as a subsequence
// We need to find shortest one here

// Approach - we first find the LCS and then put all the remaning characters in same order in this LCS sequence

// SPOJ - http://www.spoj.com/problems/ADFRUITS/

int32_t main(){
	string a, b;
	
	while(cin >> a >> b){
		int n = a.size(), m = b.size();
		
		int dp[n+1][m+1];
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				dp[i][j] = 0;
			}
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		int len = dp[n][m];
		int l = n, r = m;
		string s = "";
		while(l && r){
			if(a[l-1] == b[r-1]){
				s += a[l-1];
				l--; r--;
			}
			else if(dp[l-1][r] > dp[l][r-1]){
				l--;
			}
			else
				r--;
		}
		reverse(s.begin(),s.end());
		
		
		// Forming answer
		string ans = "";
		
		int l1 = -1, l2 = -1;
		for(auto x : s){
			int pos1 = a.find(x,l1+1);
			int pos2 = b.find(x,l2+1);
			for(int i = l1+1; i < pos1; i++)
				ans += a[i];
			for(int i = l2+1; i < pos2; i++)
				ans += b[i];
				
			ans += x;
			
			l1 = pos1;
			l2 = pos2;
			
		}
		for(int i = l1+1; i < n; i++)
			ans += a[i];
		for(int i = l2+1; i < m; i++)
			ans += b[i];
		
		cout << ans << endl;
		
	}
	
	return 0;
}

