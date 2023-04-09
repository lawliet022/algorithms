#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const int MOD2 = 999999937;
const double PI = acos(-1.0);

vector<pair<int,int>> getHash(string &s){
	int n = s.size();
	vector<pair<int,int>> h(n+1,{0LL,0LL});
	int p = 31, p2 = 37;
	for(int i = 0; i < n; i++){
		h[i+1].first = (h[i].first + (s[i] - 'a' + 1) * p % MOD) % MOD;
		h[i+1].second = (h[i].second + (s[i] - 'a' + 1) * p2 % MOD2) % MOD2;
		p = (p * 31) % MOD;
		p2 = (p2 * 37) % MOD2;
	}
	return h;
}

int32_t main(){
	string s, t;
	cin >> s >> t;
	
	vector<pair<int,int>> h = getHash(s);
	auto hs = getHash(t).back();
	
	
	cerr << h.back().first << " " << hs.first << endl;
	cerr << h.back().second << " " << hs.second << endl;
	
	int m = t.size();
		
	int n = s.size();
	int p[n+2] = {0};
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = (p[i-1] * 31) % MOD;
		
	int p2[n+2] = {0};
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
		p2[i] = (p2[i-1] * 37) % MOD2;
	
	int ans = 0;
	for(int i = m; i <= (int)s.size(); i++){
		int hh = (h[i].first - h[i-m].first) % MOD;
		if(hh < 0)
			hh += MOD;
		int hh2 = (h[i].second - h[i-m].second) % MOD2;
		if(hh2 < 0)
			hh2 += MOD2;
		int match1 = (hs.first * p[i-m]) % MOD;
		int match2 = (hs.second * p2[i-m]) % MOD2;
		if(hh == match1 && hh2 == match2)
			ans++;
	}
	cout << ans << endl;
	
	
	
	
	return 0;
}
