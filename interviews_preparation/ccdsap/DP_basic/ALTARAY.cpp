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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int dp[n] = {0};
		dp[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			if(a[i]*a[i+1] < 0)
				dp[i] = dp[i+1] + 1;
			else
				dp[i] = 1; 
		}
		
		for(int i = 0; i < n; i++)
			cout << dp[i] << " ";
		cout << endl;
	}

	return 0;
}

