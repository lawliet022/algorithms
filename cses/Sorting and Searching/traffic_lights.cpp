#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n, q;
	cin >> n >> q;
	map<int,int> m;
	set<pair<int,int>> s;
	s.insert({0LL,n});
	m[n]++;
	while(q--){
		int x;
		cin >> x;
		auto p = s.lower_bound({x+1,x+1});
		p--;
		m[(*p).second - (*p).first]--;
		if(m[(*p).second - (*p).first] == 0){
			m.erase(m.find((*p).second - (*p).first));
		}
		if(x - (*p).first){
			s.insert({(*p).first,x});
			m[x - (*p).first]++;
		}
		if((*p).second - x){
			s.insert({x,(*p).second});
			m[(*p).second - x]++;
		}
		s.erase(p);
		cout << (*(--m.end())).first << " ";
	}
	
	return 0;
}
