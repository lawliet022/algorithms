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

bool isPossible(int a[], int sep, int n, int c){
	int cnt = 1;				// No of cows placed
	int prev = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] - prev >= sep){		// can place cow on a[i]?
			cnt++;
			prev = a[i];
		}
	}
	if(cnt >= c)
		return true;
	else
		return false;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n, c;
		cin >> n >> c;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		
		sort(a,a+n);
		
		int l = 1, r = 1e9 + 5;
		
		int ans = -1;
		while(l <= r){
			int mid = (l+r)/2;
			if(isPossible(a,mid,n,c)){
				ans = mid;
				l = mid+1;
			}
			else{
				r = mid-1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

