#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
//#define int	long long
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

bool solve(int a[], int i, int n, int sumi,int target, vi &v){
	if(i == n){
		return false;
	}
	if(sumi == target){
		cout << "Found\n";
		for(auto x : v){
			cout << x << " ";
		}
		return true;
	}
	sumi += a[i];
	v.PB(a[i]);
	if(solve(a,i+1,n,sumi,target,v))
		return true;
	sumi -= a[i];
	v.pop_back();
	if(solve(a,i+1,n,sumi,target,v)){
		return true;
	}
	return false;
}


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	int sumi = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sumi += a[i];
	}
	vi v;				// To store ans
	if(sumi % 2){
		cout << "Not Found";
		return 0;
	}
	if(!solve(a,0,n,0,sumi/2,v)){
		cout << "Not Found\n";
	}
		
	// Using DP
	const int MAX = 100005;
	int dp[n+1][MAX];					// Make this DP table global as it is of 10^7 size.. Also no ll for 10^7 int array
	 for(int i = 0; i <= n; i++)
		for(int j = 0; j < MAX; j++)
			dp[i][j] = 0;
			
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= sumi; j++){
			dp[i+1][j] = dp[i][j] + (j >= a[i] ? dp[i][j-a[i]] : 0);
		}
	}
	if(dp[n][sumi/2])
		cout << "YES\n";
	else
		cout << "NO\n";
	
	// subset sum is a np hard problem

	return 0;
}

