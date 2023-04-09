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
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int cnt[10] = {0};
	for(int i = 0; i < n; i++){
		cnt[s[i]-'0']++;
	}
	int c = 0;
	for(int i = 0; i < 10; i++){
		if(cnt[i] % 2)
			c++;
	}
	if(c == 0){			// No deletion req
		cout << -1;
		return 0;
	}
	if(c == 1){			// 1 delete req
		cout << 0 << endl;
		return 0;
	}
	
	int next[10][n+1];
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < n; j++)
			next[i][j] = -1;
	
	next[s[n-1]-'0'][n-1] = n-1;
	
	for(int i = n-2; i >= 0; i--){
		for(int j = 0; j < 10; j++)
			next[j][i] = next[j][i+1];
		next[s[i]-'0'][i] = i;
	}
	
	int ans = 1e9;
	for(int i = 0; i < n; i++){
		if(cnt[s[i]-'0'] % 2){
			int last = i;
			for(int j = 0; j < 10; j++){
				if(cnt[j] % 2){
					if(next[j][i] == -1){
						last = 1e9;
						break;
					}
					last = max(last,next[j][i]);
				}
			}
			ans = min(ans,last-i);
		}
	}
	cout << ans << endl;
	

	return 0;
}

