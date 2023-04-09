#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	vector<string> res;
	do{
		res.push_back(s);
	}
	while(next_permutation(s.begin(),s.end()));
	
	cout << res.size() << endl;
	for(auto x : res){
		cout << x << endl;
	}
	
	return 0;
}

