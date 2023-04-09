#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


const int mod = (int)1e9 + 7;
const int mod2 = 999999937;
vector<pair<int,int>> getHash(string &s){
	int n = s.size();
	vector<pair<int,int>> h(n+1,{0LL,0LL});
	int p = 31, p2 = 37;
	for(int i = 0; i < n; i++){
		h[i+1].first = (h[i].first + (s[i] - 'a' + 1) * p % mod) % mod;
		h[i+1].second = (h[i].second + (s[i] - 'a' + 1) * p2 % mod2) % mod2;
		p = (p * 31) % mod;
		p2 = (p2 * 37) % mod2;
	}
	return h;
}



int32_t main(){
	string s;
	cin >> s;
	
	vector<pair<int,int>> h = getHash(s);
		
	int n = s.size();
	int p[n+2] = {0};
	p[0] = 1;
	for(int i = 1; i <= n; i++)
		p[i] = (p[i-1] * 31) % mod;
		
	int p2[n+2] = {0};
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
		p2[i] = (p2[i-1] * 37) % mod2;
	
	vector<int> ans;
	for(int i = 1; i < n; i++){
		int a1 = h[i].first;
		int a2 = h[i].second;
		
		a1 = (a1 * p[n-i]) % mod;
		a2 = (a2 * p2[n-i]) % mod2;
		
		int b1 = (h[n].first - h[n-i].first) % mod;
		if(b1 < 0)
			b1 += mod; 
		int b2 = (h[n].second - h[n-i].second) % mod2;
		if(b2 < 0)
			b2 += mod2; 
					
		if(a1 == b1 && a2 == b2){
			ans.push_back(i);
		}
	}
	
	for(auto x : ans)
		cout << x << " ";
	
	
	
	return 0;
}
