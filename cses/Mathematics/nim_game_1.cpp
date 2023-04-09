#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int x, xoriar = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			xoriar ^= x;
		}
		if(xoriar){
			cout << "first\n";
		}
		else{
			cout << "second\n";
		}
	}
	
	return 0;
}
