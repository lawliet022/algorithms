#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(i == 1){
			cout << 0 << endl;
		}
		else if(i == 2){
			cout << 6 << endl;
		}
		else if(i == 3){
			cout << 28 << endl;
		}
		else{
			int total_ways = i*i*(i*i-1)/2;					// total ways we can place 2 knights on a i*i board
			total_ways -= (i-2) * (i-2) * 2 + 2 * (i-2);	// invalid positions 2 row down
			total_ways -= (i-1) * (i-4) * 2 + 4 * (i-1);	// invalid positions 1 row down
			
			cout << total_ways << endl;						// ans = total ways - incorrect ways
		}
	}
	
	return 0;
}
