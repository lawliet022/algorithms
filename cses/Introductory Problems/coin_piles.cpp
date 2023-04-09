#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

void solve(){
	int a, b;
	cin >> a >> b;
	if((2*a-b) % 3){
		cout << "NO\n";
		return;
	}
	int y = (2*a - b) / 3;
	if(y < 0){
		cout << "NO\n";
		return;
	} 
	int x = a - 2 * y;
	if(x < 0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
