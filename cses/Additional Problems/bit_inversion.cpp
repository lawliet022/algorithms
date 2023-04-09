#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	string s;
	cin >> s;
	int n = s.size();
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = (s[i] == '1' ? 1 : 0);
	}
	
	vector<pair<int,int>> v;
	
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			if(v.size() == 0 || v.back().second != i-1){
				v.push_back({i,i});
			}
			else{
				v.back().second = i;
			}
		}
	}
	
	set<pair<int,int>> st;
	for(auto x : v){
		st.insert(x);
	}
	
	int q;
	cin >> q;
	while(q--){
		int pos;
		cin >> pos;
		if(a[pos] == 1){
			auto p = st.upper_bound({pos,pos});
			p--;
			if(*p.first == pos){
				if(*p.first + 1 <= *p.second)
					st.insert({*p.first+1,*p.second);
				st.erase(p);
			}
			else if(*p.second == pos){
				if(*p.second - 1 >= *p.first)
					st.insert({*p.first,*p.second-1);
				st.erase(p);
			}
			else{
				st.insert({*p.first,pos-1});
				st.insert({pos+1,*p.second});
				st.erase(p);
			}
			a[pos] = 0;
		}
		else{
			// merge both sides
			if(pos-1 >= 0 && pos+1 < n && a[pos-1] == 1 && a[pos+1] == 1){
				auto p = st.lower_bound({pos,pos});
				auto r = p;
				r--;
				s.insert(
			}
		}
	}
	
	return 0;
}
