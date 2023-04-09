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


vi comphash(string s, string t){
	vi v;
	if(t.size() > s.size())
		return v;
	
	int n = s.size();
	int p = 31;
	int mod = 1e9+7;
	
	int pa[n+1] = {0};
	pa[0] = 1;
	for(int i = 1; i <= n; i++){
		pa[i] = (pa[i-1]*p)%mod;
	}
	int ans[n+1] = {0};
	
	for(int i = 0; i < n; i++){
		ans[i+1] = ans[i] + (s[i] - 'a' + 1)*pa[i];
		ans[i+1] %= mod;
	}
	
	int x = t.size();
	
	int cp = 0;
	
	for(int i = 0; i < x; i++){
		cp += (t[i] - 'a' + 1)*pa[i];
		cp %= mod;
	}
	if(cp < 0)
		cp += mod;
		
	for(int i = 0; i <= n-x; i++){
		int hs = ans[i+x] - ans[i];
		if(hs < 0)	hs += mod;
		int temp = cp*pa[i];
		temp %= mod;
		if(temp < 0)	temp += mod;
		if(hs == temp)
			v.PB(i);
	}
	return v;
}



int32_t main(){
	int n;
	string s, t;	
	while(cin >> n){
		cin >> t >> s;
		vi v = comphash(s,t);
		for(auto x : v){
			cout << x << endl;
		}
		cout << endl;
	}

	return 0;
}
