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


int modpow(int a, int b, int mod){
	int res = 1;
	a %= mod;
	while(b > 0){
		if(b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}


int modinv(int a, int m){
	return modpow(a,m-2,m);
}


int32_t main(){
	// Example finding solution for
	//x = 3 mod 5
	//x = 4 mod 7
	//x = 2 mod 3
	
	int a[3] = {3,4,2};
	int m[3] = {5,7,3};
	
	// sol = SUM(ak * Xk * Xk^-1)		where Xk = m[0]*m[1]*..m[n]/m[k]
	
	int sol = a[0]*(m[1]*m[2])*modinv(m[1]*m[2],m[0]) + a[1]*(m[0]*m[2])*modinv(m[0]*m[2],m[1]) 
				+ a[2]*(m[0]*m[1])*modinv(m[0]*m[1],m[2]);
	
	cout << sol;
	
	// It has infinte many solution. ex. sol + m1*m2..*mn , sol + 2*m1*m2..*mn, etc

	return 0;
}
