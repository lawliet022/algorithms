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
	int n = s.size();
	s += s;
	
	vector<pair<int,int>> h = getHash(s);
	
	int p[n+2] = {0};
	p[0] = 1;
	for(int i = 1; i <= n; i++){
		p[i] = (p[i-1] * 31) % mod;
	}
 
	int p2[n+2] = {0};
	p2[0] = 1;
	for(int i = 1; i <= n; i++){
		p2[i] = (p2[i-1] * 37) % mod2;
	}
	
	
	auto match = [&](int x, int y, int len){
		int h11 = (h[x+len].first - h[x].first + mod) % mod;
		int h12 = (h[x+len].second - h[x].second + mod2) % mod2;
		h11 = h11 * p[y-x] % mod;
		h12 = h12 * p2[y-x] % mod2;
		
		int h21 = (h[y+len].first - h[y].first + mod) % mod;
		int h22 = (h[y+len].second - h[y].second + mod2) % mod2;
				
		if(h11 == h21 && h12 == h22){
			return true;
		}
		return false;
	};
	
	
	int cur = 0;
	for(int i = 1; i < n; i++){
		if(s[cur] != s[i]){
			if(s[cur] > s[i])
				cur = i;
			continue;
		}
		int l = 1, r = n, res = 1;
		while(l <= r){
			int mid = (l + r) / 2;
			if(match(cur,i,mid)){
				res = mid;
				l = mid+1;
			}
			else{
				r = mid - 1;
			}
		}
		if(s[cur+res] > s[i+res]){
			cur = i;
		}
	}
	
	cout << s.substr(cur,n) << endl;
	
 
	
	
	return 0;
}
