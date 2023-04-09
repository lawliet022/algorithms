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

bool findOneSolution(int a, int b, int &x, int &y, int c, int &g){
	g = extgcd(abs(a),abs(b),x,y);
	if(c % g)
		return false;
	x *= c/g;
	y *= c/g;
	if(a < 0)
		x = -x;
	if(b < 0)
		y = -y;
	return true;
}



int32_t main(){
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		int a, b, c, p;
		cin >> a >> b >> c >> p;
		int gbc = __gcd(b,c);
		int g = __gcd(a,gbc);
		
		int x1, y1, g1;
		findOneSolution(a,gbc,x1,y1,p,g1);
		
		int x2, y2, g2;
		findOneSolution(b,c,x2,y2,gbc,g2);
		if(x2 < 0){
			
		}
		
		
		
	}


	return 0;
}
