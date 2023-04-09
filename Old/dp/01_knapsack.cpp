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

//TestCase :- 
	//int val[] = {60, 100, 120}; 
	//int wt[] = {10, 20, 30}; 
	//int  W = 50; 
	//Ans = 220

// Recursive Approach
int solve(int wt[], int val[], int avaible, int item, int n){
	if(avaible == 0 || item == n){
		return 0;
	}
	int a = 0, b = 0;
	if(wt[item] <= avaible){
		a = val[item] + solve(wt,val,avaible-wt[item],item+1,n);
	}
	b = solve(wt,val,avaible,item+1,n);
	
	return max(a,b);
}
int dp2[5000][50];

int topDown(int wt[], int val[], int avaible, int item, int n){
	if(avaible <= 0 || item <= 0)
		return 0;
	int &ans = dp2[avaible][item];
	if(ans != -1){
		return ans;
	}
	int a = 0, b = 0;
	if(wt[item-1] <= avaible){
		a = val[item-1] + topDown(wt,val,avaible-wt[item-1],item-1,n);
	}
	b = topDown(wt,val,avaible,item-1,n);
	ans = max(a,b);
	return ans;
}


int32_t main(){
	int n;
	cin >> n;
	int wt[n], val[n];
	for(int i = 0; i < n; i++)
		cin >> wt[i];
	for(int i = 0; i < n; i++)
		cin >> val[i];
	
	int x;
	cin >> x;
	
	int dp[n+5][x+2] = {0};
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= x; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(wt[i-1] <= j){
				dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[n][x] << endl;
	
	// Recursive
	cout << solve(wt,val,x,0,n) << endl;
	
	// Top down
	memset(dp2,-1,sizeof(dp2));
	cout << topDown(wt,val,x,n,n) << endl;
	
	return 0;
}

