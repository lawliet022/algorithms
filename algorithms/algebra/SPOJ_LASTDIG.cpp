#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int getLastDigit(int a, int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = res*a;
			res %= 10;
		}
		a = (a*a)%10;
		b >>= 1;
	}
	return res;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << getLastDigit(a % 10,b) << "\n";
	}


	return 0;
}
