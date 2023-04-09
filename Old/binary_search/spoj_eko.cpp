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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

bool isPossible(int a[], int n, int x, int m){
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(x < a[i]){
			ans += a[i]-x;
		}
	}
	if(ans >= m)
		return true;
		
	else
		return false;
}



int32_t main(){
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	int ans = -1;
	int l = 0, r = 1e9;
	
	while(l <= r){
		int mid = (l+r)/2;
		if(isPossible(a,n,mid,m)){
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	
	cout << ans;

	return 0;
}

