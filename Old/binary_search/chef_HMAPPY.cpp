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


bool possible(int a[], int b[], int n, int candies, int m){
	for(int i = 0; i < n; i++){
		if(a[i] * b[i] <= candies){
			continue;
		}
		else{
			int toGive = a[i] - candies/b[i];
			m -= toGive;
			if(m < 0)
				return false;
		}
	}
	return true;
}


int32_t main(){
	int n, m;
	cin >> n >> m;
	
	int  a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	
	int l = 0, r = 1e18;
	int ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(possible(a,b,n,mid,m)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	cout << ans << endl;

	return 0;
}

