#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

// zero at end = 2 * 5
// count the number of 5s in n! prime factorisation because count(2s) > count(5s)


int32_t main(){
	int n;
	cin >> n;
	
	int ans = 0, cur = 5;
	while(cur <= n){
		ans += n / cur;
		cur *= 5;
	}
	cout << ans << endl;
	
	return 0;
}
