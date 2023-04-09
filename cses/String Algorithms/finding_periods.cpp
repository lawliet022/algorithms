#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

vector<int> z(string s) {
	int n = s.size();
	vector<int> z(n,0);
	int x = 0, y = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0LL,min(z[i-x],y-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			x = i; y = i+z[i]; z[i]++;
		}
	}
	return z;
}



int32_t main(){
	string s;
	cin >> s;
	
	vector<int> v = z(s);
	
	vector<int> ans;
	int n = s.size();
	ans.push_back(n);
		
	for(int i = n-1; i > 0; i--){
		if(v[i] == (n-i)){
			ans.push_back(i);
		}
	}
	
	reverse(ans.begin(),ans.end());
	for(auto x : ans){
		cout << x << " ";
	}
	
	
	
	return 0;
}
