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
		if(n <= 90){
			int p = n / 10;
			int ans = -1;
			for(int j = 9; j >= 9-p; j--){
				if(n % 10 == j){
					ans = (10 - j);
					break;
				}
			}
			cout << ans << endl;
		}
		else{
			cout << 10 - (n % 10) << endl;
		} 
	}

	return 0;
}

