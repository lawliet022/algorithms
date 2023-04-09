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
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int pref[n+1] = {0};
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i-1] ^ a[i-1];
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << (pref[r] ^ pref[l-1]) << endl;
	}
	
	
	return 0;
}
