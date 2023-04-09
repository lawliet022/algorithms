#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	
	n++;
	
	int ans = 0;
	
	for(int i = 0; i <= 60; i++){
		ans += (1LL<<i) * (n / (1LL<<(i+1)));
		int rem = n - (n / (1LL<<(i+1)))*(1LL<<(i+1));
		rem -= (1LL<<i);
		if(rem > 0)
			ans += rem;
	}
	cout << ans << endl;
	
	
	return 0;
}
