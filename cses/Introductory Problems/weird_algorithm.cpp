#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	while(n != 1){
		cout << n << " ";
		if(n % 2){
			n = n * 3 + 1;
		}
		else{
			n >>= 1;
		}
	}
	cout << n << endl;
	
	return 0;
}
