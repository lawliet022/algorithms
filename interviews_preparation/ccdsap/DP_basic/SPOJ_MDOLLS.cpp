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
		vector<pii> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i].F >> a[i].S;
			
		sort(a.begin(),a.end(),[&](pii a, pii b){
				if(a.F != b.F)
					return a.F > b.F;
				else
					return a.S < b.S;
			});
		
		vector<pii> dp;
		dp.PB(a[0]);
		
		for(int i = 1; i < n; i++){
			if(a[i].S >= dp.back().S){
				dp.PB(a[i]);
			}
			else{
				int l = 0, r = dp.size()-1;
				int p = -1;
				while(l <= r){					// Finding first doll whose height is min possible but greater than cur doll 
					int mid = (l+r)/2;
					if(a[i].S < dp[mid].S){
						p = mid;
						r = mid-1;
					}
					else
						l = mid+1;
				}
				dp[p] = a[i];
			}
		}
		cout << dp.size() << endl;
	}

	return 0;
}

