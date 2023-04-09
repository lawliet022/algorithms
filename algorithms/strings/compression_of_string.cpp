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

// Return if there exists a prefix of string such that it can be concatenated mulitple times to get the actual string

vi prefixFunc(string s){
	int n = s.size();
	vi pi(n+1,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int32_t main(){
	string s = "aabaabaab";
	int n = s.size();
	vi pi = prefixFunc(s);
	
	int k = n - pi[n-1];
	cout << (n % k == 0 ? k : n);

	return 0;
}
