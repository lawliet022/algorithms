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

int32_t main(){
	int a[] = {5,2,1,5};
	int n = sizeof(a)/sizeof(int);
	
	int dp[n] = {0};
	dp[0] = a[0];
	dp[1] = max(a[0],a[1]);
	
	for(int i = 2; i < n; i++){
		dp[i] = max(a[i] + dp[i-2], dp[i-1]);
	}
	cout << dp[n-1] << endl;

	return 0;
}
