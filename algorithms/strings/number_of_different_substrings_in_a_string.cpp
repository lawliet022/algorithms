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


// O(n^2logn) approach
int getCount(string s){
	int n = s.size();
	int p = 31;
	int mod = MOD;
	int h[n+1] = {0};
		
	int pa[n+1] = {0};
	pa[0] = 1;
	
	for(int i = 1; i <= n; i++)
		pa[i] = (pa[i-1]*p)%mod;
		
	for(int i = 0; i < n; i++){
		h[i+1] = (h[i] + (s[i] - 'a' + 1)*pa[i]);
		h[i+1] %= mod;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		set<int> s;
		for(int j = 0; j <= n-i; j++){
			int hs = h[j+i] - h[j];
			if(hs < 0)	hs += mod;
			hs = modmul(hs,pa[n-j],mod);
			s.insert(hs);
		}
		cnt += s.size();
	}
	
	return cnt;
}

int worst(string s){
	int count = 0;
	int n = s.size();
	for(int i = 1; i <= n; i++){
		set<string> w;
		for(int j = 0; j <= n-i; j++){
			w.insert(s.substr(j,i));
		}
		count += w.size();
	}
	return count;
}

int32_t main(){
	string s = "abcab";
	
	int me = getCount(s);
	int brute = worst(s);
	
	cout << me << " " << brute << endl;
	
	return 0;
}
