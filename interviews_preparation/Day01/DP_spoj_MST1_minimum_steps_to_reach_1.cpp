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


//Problem statement is very easy . On a positive integer, you can perform any one of the following 3 steps.
 //1.)  Subtract 1 from it. ( n = n - 1 ) 
 //2.)  If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )
 //3.)  If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  )
//Given a positive integer  n and you task is find the minimum number of steps that takes n to one .


const int MAX = 2e7 + 5;
int dp[MAX];

int32_t main(){
	
	dp[1] = 0;
	
	for(int i = 2; i < MAX; i++){
		dp[i] = dp[i-1] + 1;		// Subtacting 1
		if(i % 2 == 0)
			dp[i] = min(dp[i/2] + 1, dp[i]);		// divide by 2
		if(i % 3 == 0)
			dp[i] = min(dp[i/3] + 1, dp[i]);		// divide by 3
	} 
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		int n;
		cin >> n;
		cout << "Case " << test++ << ": " << dp[n] << endl;
	}

	return 0;
}

// Greedy fails on n = 10 as answer is 3 not 4
