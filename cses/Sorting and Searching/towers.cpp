#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	multiset<int> s;
	s.insert(a[n-1]);
	for(int i = n-2; i >= 0; i--){
		auto p = s.lower_bound(a[i]);
		if(s.size() == 0 || p == s.begin()){
			s.insert(a[i]);
			continue;
		}
		--p;
		s.erase(p);
		s.insert(a[i]);
	}
	
	cout << s.size() << endl;
	
	return 0;
}
