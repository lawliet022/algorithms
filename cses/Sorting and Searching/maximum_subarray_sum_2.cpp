#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, a, b;
	cin >> n >> a >> b;
	int v[n];
	int pref[n] = {0};
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	pref[0] = v[0];
	for(int i = 1; i < n; i++){
		pref[i] += pref[i-1] + v[i];
	}
	int mini[n+1][20];
	for(int i = 0; i < n; i++){
		mini[i][0] = pref[i];
	}
	for(int i = 1; (1<<i) <= n; i++){
		for(int j = 0; j + (1<<i) <= n; j++){
			mini[j][i] = min(mini[j][i-1],mini[j+(1<<(i-1))][i-1]);
		}
	}
	int LOG[n+1];
	LOG[1] = 0;
	for(int i = 2; i <= n; i++){
		LOG[i] = LOG[i>>1] + 1;
	}
	
	auto getMin = [&](int l, int r){
		int p = r - l + 1;
		p = LOG[p];
		return min(mini[l][p],mini[r-(1<<p)+1][p]);
	};
	int ans = pref[a-1];
	for(int i = a; i < n; i++){
		int l = max(-1LL,i-b);
		int r = max(0LL,i-a);
		if(l == -1){
			ans = max(ans,pref[i]);
		}
		ans = max(ans,pref[i]-getMin(max(l,0LL),r));
		
	}
	cout << ans << endl;
	
	
	
	return 0;
}
