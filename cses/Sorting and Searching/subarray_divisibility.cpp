#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	map<int,int> m;
	m[0] = 1;
	int pref = 0, ans = 0;
	for(int i = 0; i < n; i++){
		pref += a[i];
		int cur = pref % n;
		if(cur < 0)
			cur += n;
		if(m.count(cur)){
			ans += m[cur];
		}
		m[cur]++;
	}
	cout << ans << endl;
	
	
	return 0;
}
