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


// Given n steps.. and you can walk at most k steps at a time.. find number of possible ways to reach nth step

int solve(int n, int k){
	if(n <= 1)
		return 1;
	int ans = 0;
	for(int i = 1; i <= min(n,k); i++)
		ans += solve(n-i,k);
	return ans;	
}


int32_t main(){
	int n, k;			// k >= 1 always
	cin >> n >> k;
	
	cout << solve(n,k);

	return 0;
}

