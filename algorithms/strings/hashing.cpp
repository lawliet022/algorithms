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

int comphash(string s){
	int n = s.size();
	int p = 31; 		// take 53 for uppercase as well
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


int32_t main(){
	cout << comphash("hello");		// Make sure no uppercase as p = 31

	return 0;
}
