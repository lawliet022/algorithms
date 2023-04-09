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


// If you don't use hashing, time complexity will be O(n*mlog(n)) where n is no
// of strings and m is size of strings and nlogn is for sorting and m is for comparison
// we can reduce these m comparison to 1 by hashing

// So complexity will become 0(n*m + nlogn) Where O(nm) is for computing hash of 
// n strings ans nlogn for sorting integer hashes

int comphash(string s){
	int p = 31; 		// take 53 for uppercase as well
	int m = 1e9+7;
	int ans = 0;
	int t = 1;
	for(int i = 0; i < (int)s.size(); i++){
		ans += (s[i] - 'a' + 1)*t;
		t = (t*p)%m;
		ans %= m;
	}
	return ans;
	
}



vector<vi> getDuplicates(vector<string> v){
	int n = v.size();
	vector<pii> w;
	for(int i = 0; i < (int)v.size(); i++){
		w.PB({comphash(v[i]),i});
	} 
	sort(w.begin(),w.end());
	vector<vi> dup;
	for(int i = 0; i < n; i++){
		if(i == 0 || w[i].F != w[i-1].F)
			dup.emplace_back();
		dup.back().emplace_back(w[i].S);
	}
	return dup;
	
	
}

int32_t main(){
	vector<string> v = {"abc","defgh","abc","pqrs","defg","defgh","abc","wxy"};
	
	vector<vector<int>> g = getDuplicates(v);
	
	for(int i = 0; i < (int)g.size(); i++){
		cout << v[g[i][0]] << " -> ";
		for(auto x : g[i]){
			cout << x << " ";
		} 
		cout << endl;
	}

	return 0;
}
