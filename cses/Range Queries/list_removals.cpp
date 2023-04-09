#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update> ost;


int32_t main(){
	int n;
	cin >> n;
	ost s;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert({i,x});
	}
	
	while(n--){
		int x;
		cin >> x;
		x--;
		auto p = s.find_by_order(x);
		cout << (*p).second << " ";
		s.erase(p);
	}
	
	
	return 0;
}
