#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int x, y;
		cin >> x >> y;
		int p = max(x,y);
		int done = (p-1) * (p-1);		// used numbers till previous spiral chain
		
		if(x == y){
			cout << done + x << endl;
		}
		else if(x > y){
			if(p % 2 == 0){
				cout << p * p - y + 1 << endl;
			}
			else{
				cout << done + y << endl;
			}
		}
		else{
			if(p % 2 == 0){
				cout << done + x << endl;
			}
			else{
				cout << p * p - x + 1 << endl;
			}
		}
	}
	
	return 0;
}
