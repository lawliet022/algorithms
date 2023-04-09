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

// ----- Phi for range [1,N] ------------------

// Phi using sieve (bitwise) -- Remember sieve is only good till 10^7 or something -- O(nloglong(n))

#define max 10000000
int a[(max>>5) + 1];

#define get(i) ((a[i>>5]>>(i&31))&1)
#define set(i) (a[i>>5] |= (1<<(i&31)))

int p[max+10];

void sieve(){

	int n = max;
	for(int i = 1; i <= n; i++)
		p[i] = i;

	set(1);

	for(int i = 2; i <= n; i++){				// remember i <= n and not i*i <= n here
		if(!get(i)){
			for(int j = 2*i; j <= n; j += i){
				p[j] -= p[j]/i;
				set(j);
			}
		}
	}
}

int phi2(int n){
	if(n == 1)
		return 1;

	if(p[n] == n){
		return n-1;
	}
	return p[n];
}


auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
int myrand(int mod){
	return mt()%mod;
}

int32_t main(){
	sieve();
	while(1){
		int n = myrand(10000000)+5;
		cout << "n = " << n << endl;
		if(phi(n) != phi2(n)){
			cout << "Failed for " << n << endl;
			cout << phi(n) << " " << phi2(n) << endl;
			return 0;
		}
		else
			cout << "Passed for " << n << "\n";
	}
	

	return 0;
}
