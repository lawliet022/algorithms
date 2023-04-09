#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	int a[n];
	map<int,int> ma;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] %= m;
		ma[a[i]]++;
	}
	int q;
	cin >> q;
	while(q--){
		int type;
		cin >> type;
		if(type == 1){
			int pos, val;
			cin >> pos >> val;
			val %= m;
			pos--;
			ma[a[pos]]--;
			if(ma[a[pos]] == 0){
				ma.erase(ma.find(a[pos]));
			}
			a[pos] = val;
			ma[val]++;
		}
		else{
			int val;
			cin >> val;
			if(ma.count(val)){
				cout << ma[val] << endl;
			}
			else{
				cout << 0 << endl;
			}
		}
	}
	
	return 0;
}
