#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

// constant space solution 

int32_t main(){
	int n;
	cin >> n;
	int cur = 0;
	for(int i = 0; i < n-1; i++){
		int x;
		cin >> x;
		cur += x;
	}
	
	cout << n*(n+1)/2LL  - cur << endl;
	
	
	return 0;
}
