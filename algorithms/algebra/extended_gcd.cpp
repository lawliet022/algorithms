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

int extgcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = extgcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}


int32_t main(){
	int x, y;
	int gc = extgcd(-4, -20, x, y);
	cout << gc << " " << x << " " << y << "\n";


	return 0;
}
