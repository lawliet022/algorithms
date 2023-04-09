#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        int dp1[n], dp2[n];
        dp1[0] = 1, dp2[n-1] = 1;
        
        for(int i = 1; i < n; i++){
            dp1[i] = 1;
            for(int j = 0; j < i; j++)
                if(a[j] < a[i])
                    dp1[i] = max(dp1[j]+1,dp1[i]);
        }
        for(int i = n-1; i >= 0; i--){
            dp2[i] = 1;
            for(int j = n-1; j > i; j--)
                if(a[j] < a[i])
                    dp2[i] = max(dp2[j]+1,dp2[i]);
        }
        int ans = 1;
        for(int i = 0; i < n; i++){
            ans = max(ans,dp1[i]+dp2[i]-1);
        }
        cout << ans << endl;
    }


	return 0;
}
