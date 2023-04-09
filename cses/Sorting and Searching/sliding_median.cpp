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
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ost s;
	for(int i = 0; i < k; i++){
		s.insert({a[i],i});
	}
	int pos = (k % 2 ? k / 2 : k / 2 - 1);
	cout << (*s.find_by_order(pos)).first << " ";
	
	for(int i = k; i < n; i++){
		s.erase(s.find({a[i-k],i-k}));
		s.insert({a[i],i});
		cout << (*s.find_by_order(pos)).first << " ";
	}
	
	
	return 0;
}
