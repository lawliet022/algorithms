#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mini[n][20];
	for(int i = 0; i < n; i++){
		mini[i][0] = a[i];
	}
	for(int i = 1; (1<<i) <= n; i++){
		for(int j = 0; j + (1<<i) <= n; j++){
			mini[j][i] = min(mini[j][i-1],mini[j+(1<<(i-1))][i-1]);
		}
	}
	int LOG[n+2];
	LOG[1] = 0;
	for(int i = 2; i <= n; i++){
		LOG[i] = LOG[i>>1] + 1;
	}
	
	auto getMin = [&](int l, int r){
		int p = r - l + 1;
		p = LOG[p];
		return min(mini[l][p],mini[r-(1<<p)+1][p]);
	};
	
	while(q--){
		int l, r;
		cin >> l >> r;
		l--;	r--;
		cout << getMin(l,r) << endl;
	}
	
	
	return 0;
}
