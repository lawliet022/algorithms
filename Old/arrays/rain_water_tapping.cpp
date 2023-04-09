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


int32_t main(){
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(a)/sizeof(int);
	
	int p[n], q[n];
	
	p[0] = a[0];
	for(int i = 1; i < n; i++)
		p[i] = max(p[i-1],a[i]);
		
	q[n-1] = a[n-1];
	for(int i = n-2; i >= 0; i--)
		q[i] = max(q[i+1],a[i]);
	
	int ans = 0;
	for(int i = 1; i < n-1; i++){
		int mn = min(p[i-1],q[i+1]);
		if(mn > a[i]){
			ans += mn-a[i];
		}
	}
	cout << ans << endl;
	

	return 0;
}

