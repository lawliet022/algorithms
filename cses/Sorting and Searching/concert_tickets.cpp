#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, m;
	cin >> n >> m;
	multiset<int> s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		if(s.size() == 0){
			cout << -1 << endl;
			continue;
		}
		auto p = s.upper_bound(x);
		if(p == s.begin()){
			cout << -1 << endl;
			continue;
		}
		p--;
		cout << *p << endl;
		s.erase(p);
	}
	
	
	return 0;
}
