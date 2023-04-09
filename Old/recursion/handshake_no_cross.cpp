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


// Recurance for catalan number is C0 = 1 and Cn = SUM(Ci*Cn-i-1) i = 0 to n-1		// Where Ci is ith catalan number

// 1 2 5 14 42 132 ... is series

// Also Cn = 2nCn / (n+1)


// https://practice.geeksforgeeks.org/problems/handshakes/0

int countWays(int n){
	if(n == 0)
		return 1;
	if(n == 1)
		return 0;
	int ans = 0;
	for(int i = 0; i < n; i += 2)
		ans += countWays(i)*countWays(n-2-i);			// Number of people on left and right of 0th person handshake
	return ans;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << countWays(n) << endl;
	}

	return 0;
}

