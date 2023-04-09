#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

struct comparator{
	bool operator()(pair<int,int> a, pair<int,int> b){
		return a > b;
	}
};


int32_t main(){
	int n;
	cin >> n;
	
	set<pair<int,int>,comparator> s;
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x > 0){
			s.insert({x,i});
		}
	}

	
	vector<pair<int,int>> ans;
	
	while(1){
		if(s.size() == 0)
			break;
		auto p = *(s.begin());
		s.erase(s.begin());
		int val = p.first;
		int player = p.second;
		set<pair<int,int>> temp, to_remove;
		for(auto x : s){
			val--;
			to_remove.insert(x);
			if(x.first > 1)
				temp.insert({x.first-1,x.second});
			if(val == 0)
				break;
		}
		if(val){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		
		for(auto x : to_remove){
			s.erase(s.find(x));
			ans.push_back({player,x.second});
		}
		
		for(auto x : temp){
			s.insert(x);
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans)
		cout << x.first << " " << x.second << endl;
	
	
	
	return 0;
}
