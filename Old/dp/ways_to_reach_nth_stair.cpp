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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

int dp3[1000];
int solve(int n, int k){
	if(n == 0)
		return 1;
	int &ans = dp3[n];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i = n-1; i >= max(n-k,0LL); i--)
		ans += solve(i,k);
	return ans;
}

int32_t main(){
	int n, k;
	cin >> n >> k;		// At most k steps at a time
	
	int dp[n+10] = {0};
	dp[0] = 1;
	
	// O(n^2)
	for(int i = 1; i <= n; i++){
		for(int j = i-1; j >= max(i-k,0LL); j--){
			dp[i] += dp[j];
		}
	}
	
	// O(n)
	int dp2[n+10] = {0};
	dp2[0] = 1;
	int sumi = dp[0];
	for(int i = 1; i <= k; i++){
		dp2[i] = sumi;
		sumi += dp2[i];
	}
	for(int i = k+1; i <= n; i++){
		dp2[i] = 2*dp2[i-1] - dp2[i-k-1];
	}
	cout << dp[n] << " " << dp2[n] << endl;
	
	// bottom up - O(n^2)
	memset(dp3,-1,sizeof(dp3));
	cout << solve(n,k) << endl;
	

	return 0;
}

