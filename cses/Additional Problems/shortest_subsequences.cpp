#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	string s;
	cin >> s;
	
	map<char,int> c = {{'A',0},{'C',1},{'G',2},{'T',3}};
	map<int,char> cr = {{0,'A'},{1,'C'},{2,'G'},{3,'T'}};
	
	int n = s.size();
	
	int next[n+1][4];
	memset(next,-1,sizeof next);
	int dp[n+1][5];
	memset(dp,0,sizeof dp);
	
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			next[i][j] = next[i+1][j];
		}
		for(int j = 0; j < 4; j++){
			if(next[i][j] != -1){
				dp[i][j] = dp[next[i][j]][4] + 1;
			}
		}
		int mini = 1e9;
		for(int j = 0; j < 4; j++)
			mini = min(mini,dp[i][j]);
		dp[i][4] = mini;
		next[i][c[s[i]]] = i;
	}
	int mini = 1e9, st = 0;
	for(auto x : c){
		if(next[0][x.second] == -1){
			cout << x.first << endl;
			return 0;
		}
		if(dp[next[0][x.second]][4] < mini){
			mini = dp[next[0][x.second]][4];
			st = x.second;
		}
	}
	string ans = "";
	ans += cr[st];
	int pos = next[0][st];
	for(int i = 0; i <= mini; i++){
		int mini = 1e9, idx = -1;
		for(int j = 0; j < 4; j++){
			if(dp[pos][j] < mini){
				mini = dp[pos][j];
				idx = j;
			}
		}
		ans += cr[idx];
		pos = next[pos+1][idx];
	}
	
	cout << ans << endl;
	
	return 0;
}
