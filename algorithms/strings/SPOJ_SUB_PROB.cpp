#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;
 
 
//--------------------- NOT YET SOLVED :( Getting TLE ------------------------------------
 
const int MAX = 1e5 + 5;
int ans[MAX];
int pa[MAX];
 
void solve(string s){
	int n = s.size();
	pa[0] = 1;
	for(int i = 1; i <= n; i++)
		pa[i] = (pa[i-1]*89)%MOD;
	
	for(int i = 0; i < n; i++){
		ans[i+1] = ans[i] + (s[i] - '0' + 1)*pa[i];
		ans[i+1] %= MOD;
	}
}
 
 
int comphash(string s){
	int n = s.size();
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += (s[i] - '0' + 1)*pa[i];
		ans %= MOD;
	}
	if(ans < 0)	ans += MOD;
	return ans;
}
 
 
 
 
int32_t main(){
	
	string s;
	cin >> s;
	int n = s.size();
	
	solve(s);
	
	int q;
	cin >> q;
	while(q--){
		string t;
		cin >> t;
		int w = comphash(t);
		int flag = 0;
		
		for(int i = 0; i <= n - (int)t.size(); i++){
			if(s[i] != t[0]){
				continue;
			}
			int temp = ans[i+t.size()] - ans[i];
			if(temp < 0)	temp += MOD;
			int x = (w*pa[i]) % MOD;
			if(x < 0)	x += MOD;
			if(temp == x){
				flag = 1;
				break;
			}
		}
		if(flag)
			cout << "Y\n";
		else
			cout << "N\n";
	}
 
	return 0;
}
