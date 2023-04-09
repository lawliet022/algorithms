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


// Approach:-
//	For all n <= 6 ans is n itself. For n > 6 we need to find a breaking point where to put ctrlA + ctrlC and then all ctrlV's
// 	See:- https://www.ideserve.co.in/learn/print-maximum-number-of-a-using-four-keys-of-special-keyboard

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dp[n+1];
        if(n <= 6){
            cout << n << endl;
            continue;
        }
        for(int i = 1; i <= 6; i++)
            dp[i] = i;
        for(int i = 7; i <= n; i++){
            dp[i] = 0;
            for(int j = i-2; j >= 2; j--){
                dp[i] = max(dp[i],(i-j)*dp[j-1]);
            }
        }
        cout << dp[n] << endl;
    }


	return 0;
}
