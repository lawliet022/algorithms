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

// Problem - GFG -> Count ways to assign unique cap to every person

// Statement - There are 100 different types of caps each having a unique id from 1 to 100. Also, there are ‘n’ persons each having
// a collection of a variable number of caps. One day all of these persons decide to go in a party wearing a cap but to look unique
// they decided that none of them will wear the same type of cap. So, count the total number of arrangements or ways such that none
// of them is wearing the same type of cap.

// Constraints: 1 <= n <= 10


vector<int> cap[105];
int dp[(1<<10)+5][105];
int allMask;

int solve(int mask, int curCap){
	if(mask == allMask){
		return 1;
	}
	if(curCap > 100)
		return 0;
	int &ans = dp[mask][curCap];
	if(ans != -1){
		return ans;
	}
	ans = 0;
	ans += solve(mask,curCap+1);
	
	for(int i = 0; i < (int)cap[curCap].size(); i++){
		if(mask&(1<<cap[curCap][i]))
			continue;
		ans += solve(mask|(1<<cap[curCap][i]),curCap+1);
	}
	return ans;
}




int32_t main(){
	int n;
	cin >> n;
	vector<int> a(n);			
	for(int i = 0; i < n; i++)
		cin >> a[i];				// No of different caps each person has
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < a[i]; j++){
			int x;
			cin >> x;
			cap[x].PB(i);
		}
	}
	allMask = (1 << n) - 1;
	memset(dp,-1,sizeof dp);
	cout << solve(0,0) << endl;
	

	return 0;
}

