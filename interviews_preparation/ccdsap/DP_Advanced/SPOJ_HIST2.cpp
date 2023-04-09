#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

const int N = 16;

int dp[(1<<N)+1][N];
int cnt[(1<<N)+1][N];
int n;

int a[N];

int solve(int mask, int cur){
	if(mask == ((1<<n)-1)){
		cnt[mask][cur] = 1;
		return a[cur];
	}
	int &ans = dp[mask][cur];
	if(ans != -1)
		return ans;
	for(int i = 0; i < n; i++){
		if(!(mask&(1<<i))){
			int val = solve(mask|(1<<i),i) + abs(a[i]-a[cur]);
			if(val > ans){
				ans = val;
				cnt[mask][cur] = 0;
			}
			if(val == ans)
				cnt[mask][cur] += cnt[mask|(1<<i)][i];
		}
	}
	return ans;
}



int32_t main(){

	while(cin >> n){
		if(!n)
			break;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		memset(dp,-1,sizeof dp);
		
		int best = 0;
		int count = 0;
		
		for(int i = 0; i < n; i++){
			int x = a[i] + solve((1<<i),i);
			if(x > best){
				best = x;
				count = 0;
			}
			if(x == best)
				count += cnt[(1<<i)][i];
		}
		
		
		cout << best + 2*n << " " << count << endl;
		
	}

	return 0;
}

