#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 9999991
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


int phi(int n){
	int res = n;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0)
				n /= i;
			res -= res/i;
		}
	}
	if(n > 1)
		res -= res/n;
	return res;
}


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

int getmodinv(int a,int m){
	int x, y;
	int g = extgcd(a, m, x, y);
	if (g != 1) {
		return -1;
	}
	else {
		x = (x % m + m) % m;
		return x;
	}
}

const int mod = 9999991;
int inv[mod];
	
void modinv(){
	int m = mod;
	inv[1] = 1;
	for(int i = 2; i < m; i++){
		inv[i] = (m - (m/i)*inv[m%i] % m) % m;
	}
}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod){
	return mt()%mod;
}

int32_t main(){
	// modinv of a wrt m does not exist when a and m are not coprime
	
	
	// Only when m is prime
	int a = 100;
	int m = MOD;
	cout << modpow(a,m-2,m) << endl;		// 1st method
	
	
	// When m is non-prime but coprime with a
	
	// Approach 1 [O(sqrt(m)*log(m))] => In this case we will have to calculate phi(m) then apply a^(phi(m)-1) % m using above approach
	a = 45*5;
	m = 16;
	cout << modpow(a,phi(m)-1,m) << endl;
	
	// Approach 2 (time complexity O(log(m))) => Using extended gcd approach
	
	/* EXPLANATION - 
		ax + my = 1 ( because gcd(a,m) = 1)
		Taking mod by m on both sides => ax % m = 1
		x is modinv
	*/
	
	a = 45*5;
	m = 16;
	cout << getmodinv(a,m) << endl;
	
	
	// Modinv wrt m of every number in range [1,m-1] in O(m)
	modinv();
	int q = inv[100];
	cout << q << endl;


	return 0;
}
