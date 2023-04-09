#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	multiset<int> s;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		s.insert(x);
	}
	sort(a,a+n);
	
	for(int i = 0; i < n; i++){
		auto p = s.lower_bound(a[i]-k);
		if(p == s.end()){
			break;
		}
		if(*p <= a[i] + k){
			s.erase(p);
		}
	}
	
	cout << m - (int)s.size() << endl;
	
	return 0;
}
