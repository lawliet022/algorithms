#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> coin = {3,5,10};


//int solve(int n, int val){			// Exponential Solution
	//if(val == 0)
		//return 1;
	//if(val < 0 || n < 0)
		//return 0;
	//int include = solve(n,val-coin[n]);
	//int exclude = solve(n-1,val);
	
	//return include+exclude;
//}





//unordered_map<string,int> lookup;
//int solve(int n, int val){			// O(n*val)
	//if(val == 0)
		//return 1;
	//if(val < 0 || n < 0)
		//return 0;
	
	//string key = to_string(n) + "@" + to_string(val);
	
	//if(lookup.find(key) == lookup.end()){
		//int include = solve(n,val-coin[n]);
		//int exclude = solve(n-1,val);
		//lookup[key] = include + exclude;
	//}

	//return lookup[key];
//}

int solve(int n, int val){
	int dp[val+2];
	for(int i = 0; i <= val; i++)
		dp[i] = 0;
	dp[0] = 1;
	for(int i = 3; i <= val; i++)
		dp[i] += dp[i-3];
	for(int i = 5; i <= val; i++)
		dp[i] += dp[i-5];
	for(int i = 10; i <= val; i++)
		dp[i] += dp[i-10];
	
	return dp[val];
}



int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << solve(3,n) << endl;
	}


	return 0;
}
