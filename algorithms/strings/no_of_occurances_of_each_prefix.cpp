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

const int MAX = 1e5;
vi pi(MAX,0);
	
vi prefixFunc(string s){
	int n = s.size();
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
	string s = "aabcaabcaa";
	int n = s.size();
	
	prefixFunc(s);
	
	int ans[n+1] = {0};
	for(int i = 0; i < n; i++){
		ans[pi[i]]++;
	}
	for(int i = n-1; i > 0; i--){
		ans[pi[i-1]] += ans[i];
	}
	for(int i = 0; i <= n; i++)
		ans[i]++;
	
	cout << "Count of occurances of each prefix \n";
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}

	return 0;
}
