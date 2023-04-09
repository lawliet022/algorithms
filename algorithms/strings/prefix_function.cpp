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

vi prefixFunc(string s){
	int n = s.size();
	vi pi(n,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}


int32_t main(){
	string s = "abcabwabcax";
	vi v = prefixFunc(s);
	
	for(auto x : v){
		cout << x << " ";
	}

	return 0;
}
