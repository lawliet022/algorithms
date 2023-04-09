#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	if(n > 1 && n < 4){
		cout << "NO SOLUTION";
		return 0;
	}
	for(int i = 2; i <= n; i += 2)
		cout << i << " ";
	
	for(int i = 1; i <= n; i += 2)
		cout << i << " ";
	
	
	return 0;
}
