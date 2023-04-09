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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<string> s(n);
		for(auto &x : s)
			cin >> x;
		
		bool dp1[n+1][n+1], dp2[n+1][n+1];			// Down and right resp.
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				dp1[i][j] = dp2[i][j] = 1;
				
				
		for(int i = n-1; i >= 0; i--){
			for(int j = n-1; j >= 0; j--){
				if(dp1[i+1][j] && dp2[i][j+1] && (s[i][j] == '.')){
					continue;
				}
				else{
					if(s[i][j] == '#'){
						dp1[i][j] = dp2[i][j] = 0;
					}
					else{
						if(dp1[i+1][j] == 0)
							dp1[i][j] = 0;
							
						if(dp2[i][j+1] == 0)
							dp2[i][j] = 0;
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(dp1[i][j] && dp2[i][j])
					cnt++;
		cout << cnt << endl;
	}

	return 0;
}

