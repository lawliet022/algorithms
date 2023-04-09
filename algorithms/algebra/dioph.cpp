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
	int x, y, g;
	if(findOneSolution(-12,20,x,y,20,g)){
		cout << "Solutions Possible. One of solution is\n";
		cout << x << " " << y << " " << g << "\n";
	}
	else
		cout << "No Solution\n";


	return 0;
}
