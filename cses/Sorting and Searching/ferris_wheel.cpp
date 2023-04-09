#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, k;
	cin >> n >> k;
	multiset<int> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	while(s.size() > 1){
		auto p = s.begin();
		s.erase(p);
		auto q = s.upper_bound(k-(*p));
		if(q != s.begin()){
			q--;
		}
		if(*q + *p <= k){
			s.erase(q);
		}
		ans++;
	}
	if(s.size()){
		ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}
