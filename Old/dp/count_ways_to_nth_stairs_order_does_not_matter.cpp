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

//There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time.
//Count the number of ways, the person can reach the top (order does not matter). 
//Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

int32_t main(){
	
	int dp[(int)1e6 + 10] = {0};
	dp[0] = 1;
	
	for(int i = 1; i <= 1e6; i++){
		dp[i] = 1 + (i/2);
	}
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}

