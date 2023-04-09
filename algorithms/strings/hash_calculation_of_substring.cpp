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


int modmul(int a, int b, int mod){
	int res = 0;
	a %= mod;
	while(b > 0){
		if(b&1)
			res = (res+a)%mod;
		a = (a*2)%mod;
		b >>= 1;
	}
	return res;
}


int modpow(int a, int b, int mod){
	int res = 1;
	a %= mod;
	while(b > 0){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int modinv(int a, int p, int m){
	return modpow(a,p*(m-2),m);
}

int comphash(string s){
	int n = s.size();
	int p = 31;
	int m = 1e9+7;
	int ans = 0;
	int t = 1;
	for(int i = 0; i < n; i++){
		ans += (s[i] - 'a' + 1)*t;
		t = (t*p)%m;
		ans %= m;
	}
	return ans;
	
}


void substring_hash(string s){
	int n = s.size();
	int p = 31;
	int m = 1e9+7;
	int ans[n] = {0};
	int t = 1;
	for(int i = 0; i < n; i++){
		ans[i+1] = ans[i] + (s[i] - 'a' + 1)*t;
		t = (t*p)%m;
		ans[i+1] %= m;
	}
	
	//  Method - 1 Modinv based
		int l = 2;
		int r = 5;
		int w = modmul((ans[r+1] - ans[l]),modinv(p,l,MOD),MOD);
		if(w < 0)
			w += MOD;
		string temp = s.substr(l,r-l+1);
		int u = comphash(temp);
		cout << u << " " << w << endl;
		
	
	// Method - 2 Raise one of the string's hash to match with other
		l = 2;
		r = 5;
		
		w = (ans[r+1] - ans[l]) % MOD;
		if(w < 0)
			w += MOD;
		temp = s.substr(l,r-l+1);
		u = comphash(temp);
		u = modmul(u,modpow(p,l,MOD),MOD);
		cout << u << " " << w << endl;
		
	
}



int32_t main(){
	string s = "helloworldisthestupidestline";
	
	substring_hash(s);
	
	return 0;
}
