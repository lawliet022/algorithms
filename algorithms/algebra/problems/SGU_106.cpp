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

pii getIntersect(pii a,pii b){
	if(a.S < b.F || b.S < a.F)
		return {-2e18,-2e18};
	int x = max(a.F,b.F);
	int y = min(a.S,b.S);
	
	return {x,y};
}


int egcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = egcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}


int32_t main(){
	int a, b, c;
	cin >> a >> b >> c;
	int x1, x2, y1, y2;
	cin >> x1 >> x2 >> y1 >> y2;
	
	if(a == 0 && b == 0){
		if(c == 0){
			cout << (x2-x1+1)*(y2-y1+1) << endl;
		}
		else{
			cout << 0 << endl;
		}
		return 0;
	}
	if(a == 0){
		if(c % b == 0 && (y1 <= c/b && c/b <= y2)){
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
		return 0;
	}
	if(b == 0){
		if(c % a == 0 && (x1 <= c/a && c/a <= x2)){
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
		return 0;
	}
	
	
	c = -c;
	if(c % __gcd(a,b)){
		cout << 0;
		return 0;
	}
	
	int x, y;
	int g = egcd(abs(a),abs(b),x,y);
	x *= c / g;
	y *= c / g;
	if(a < 0)
		x = -x;
	if(b < 0)
		y = -y;
				
	int k1 = ceil((1.0*x1-x)/(b/g));
	int k2 = floor((1.0*x2-x)/(b/g));
	
	pii p1, p2, p3, p4;
	
	if(b < 0){
		k1 = ((1.0*x1-x)/(b/g));
		k2 = ceil((1.0*x2-x)/(b/g));
		p1 = {-1e18,k1};
		p2 = {k2,1e18};
	}
	else{
		p1 = {k1,1e18};
		p2 = {-1e18,k2};
	}
	
	pii res = getIntersect(p1,p2);
	
	if(res.F == 2e18){
		cout << 0;
		return 0;
	}
		
	int k3 = floor(-(1.0*y1-y)/(a/g));
	int k4 = ceil(-(1.0*y2-y)/(a/g));
	
	
	if(a < 0){
		k3 = ceil(-(1.0*y1-y)/(a/g));
		k4 = floor(-(1.0*y2-y)/(a/g));
		p3 = {k3,1e18};
		p4 = {-1e18,k4};
	}
	else{
		p3 = {-1e18,k3};
		p4 = {k4,1e18};
	}
	
	pii res2 = getIntersect(p3,p4);
	
	if(res2.F == 2e18){
		cout << 0;
		return 0;
	}
	
	pii ans = getIntersect(res,res2);
	if(ans.F == -2e18){
		cout << 0;
		return 0;
	}
	cout << ans.S - ans.F + 1  << endl;

	return 0;
}

//17 -81 1036  
//-100000000 100000000
//-100000000 100000000

