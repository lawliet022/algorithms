#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int ans = -2e9;
	int cur = -2e9, x;
	for(int i = 0; i < n; i++){
		cin >> x;
		cur = max(x,cur + x);
		ans = max(ans,cur);
	}
	cout << ans << endl;
	
	return 0;
}
