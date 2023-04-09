#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a = 0, b = 0;
		for(auto x : s){
			if(x == '(')
				a++;
			else
				b++;
		}
		cout << min(a,b) * 2 << endl;
	}
	
	return 0;
}
