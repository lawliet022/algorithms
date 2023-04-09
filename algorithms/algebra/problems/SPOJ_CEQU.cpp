#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int32_t main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int a, b, c;
		cin >> a >> b >> c;
		if(c % __gcd(a,b)){
			cout << "Case " << test << ": No\n";
		}
		else
			cout << "Case " << test << ": Yes\n";
	}

	return 0;
}

