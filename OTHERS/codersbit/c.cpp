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


int32_t main(){
	vector<int> a = {31, 14, 22, 23, 21};
	int b = 2;
	
	int n = a.size();
	int dp[n][3000] = {0};
	
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		dp[0][0][i] = a[i];
	
	vector<int> v[n][3000];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3000; j++){
			dp[i][j] = dp[i-1][j];
			for(int k = 0; k < dp[i-1][j^a[i-1]].size(); k++){
				if(a[i-1] > v[i][j][k]){
					dp[i][j] += 
				}
			}
		}
	}

	return 0;
}

