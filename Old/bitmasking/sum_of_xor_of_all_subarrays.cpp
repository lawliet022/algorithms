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
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	int ans = 0;
	for(int i = 0; i < 31; i++){
		int odd = 0, cnt = 0;
		for(int j = 0; j < n; j++){
			if(a[j]&(1<<i))
				odd = !odd;
			if(odd)
				cnt++;
		}
		for(int j = 0; j < n; j++){
			ans += cnt*(1<<i);
			if(a[j]&(1<<i)){
				cnt = (n-j-cnt);
			}
		}
	}
	cout << ans;

	return 0;
}

