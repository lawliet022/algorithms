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

int gcd(int a, int b){
	if(b == 0)
		return a;
	else{
		return gcd(b,a%b);
	}
}

int lcm(int a, int b){
	return (a/gcd(a,b)*b);
}

int32_t main(){
	cout << gcd(5,15) << "\n";
	cout << lcm(5,15) << "\n";
	
	// lcm of more than 2 no's.. careful its not a*b*c*../__gcd(a,b,c,...)
	cout << lcm(5,lcm(10,15)) << endl;

	return 0;
}
