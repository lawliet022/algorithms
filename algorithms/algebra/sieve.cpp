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

// TIll 10^7 sieve is fine.. for 10^8 it takes more than 1 sec
// For 10^8 use bitwise sieve due to size issue

#define MAX 1000000

int prime[MAX];
void sieve(int n){
	prime[0] = prime[1] = 1;
	for(int i = 2; i*i <= n; i++){
		if(!prime[i]){
			for(int j = i*i; j <= n; j += i){
				prime[j] = 1;
			}
		}
	}
}


int a[(MAX>>5) + 10];
#define get(i) ((a[i >> 5] >> (i&31) & 1))
#define set(i) (a[i >> 5] |= 1 << (i&31))

void bitsieve(int n){
	set(1);
	for(int i = 2; i*i <= n; i++){
		if(!get(i)){
			for(int j = i*i; j <= n; j += i){
				set(j);
			}
		}
	}
}


// Limitation by size.. can't use 10^8 for this approach
int lp[MAX+5];
vector<int> p;

void linearSieve(int n){
	for(int i = 2; i <= n; i++){
		if(lp[i] == 0){
			lp[i] = i;
			p.PB(i);
		}
		for(int j = 0; j < (int)p.size() && p[j] <= lp[i] && i*p[j] <= n; j++)
			lp[i*p[j]] = p[j];
	}
}

int32_t main(){
	sieve(MAX);
	bitsieve(MAX);
	for(int i = 1; i <= 100; i++){
		if(!prime[i]){
			cout << i << " ";
		}
	}
	cout << endl;
	for(int i = 1; i <= 100; i++){
		if(!get(i)){
			cout << i << " ";
		}
	}
	cout << endl;
	
	linearSieve(MAX);

	for(int i = 0; i <= 100; i++){
		cout << p[i] << " " ;
	}
	cout << endl;
	
	
	// Using Linear approach to get factors of any number
	int x = 1000 ;
	if(x < 2){
		cout << "Factors are -> " << x << "\n";
	}
	else{
		cout << "Factors of " << x << " -> ";
		while(lp[x] != x){
			cout << lp[x] << " ";
			x = x / lp[x];
		}
		cout << lp[x] << "\n";
	}


	return 0;
}
