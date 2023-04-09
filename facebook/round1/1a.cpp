#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

bool increasing(int l[], int n){
	for(int i = 1; i < n; i++){
		if(l[i] <= l[i-1])
			return false;
	}
	return true;
}

void solve(){
	int n, k, w;
	cin >> n >> k >> w;
	int l[n], h[n];
	for(int i = 0; i < k; i++){
		cin >> l[i];
	}
	int al, bl, cl, dl;
	cin >> al >> bl >> cl >> dl;
	
	for(int i = 0; i < k; i++){
		cin >> h[i];
	}
	int ah, bh, ch, dh;
	cin >> ah >> bh >> ch >> dh;
	
	for(int i = k; i < n; i++){
		l[i] = (al * l[i-2] % dl + bl * l[i-1] % dl + cl) % dl + 1;
		h[i] = (ah * h[i-2] % dh + bh * h[i-1] % dh + ch) % dh + 1;
	}
	
	assert(increasing(l,n));
	
	
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
