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

bool canRead(int a[], int n, int per, int m){
	int cnt = 0;
	int hasRead = 0;
	for(int i = 0; i < n; i++){
		hasRead += a[i];
		if(hasRead > per){
			cnt++;
			hasRead = a[i];
		}
	}
	if(hasRead <= per){
		cnt++;
	}
	return (cnt <= m);
}


int32_t main(){
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int l = *max_element(a,a+n);
	int r = 1e18;
		
	int ans = -1;
	
	while(l <= r){
		int mid = (l+r)/2;
		if(canRead(a,n,mid,m)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	
	cout<< ans << endl;

	return 0;
}

