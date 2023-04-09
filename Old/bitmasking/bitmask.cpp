#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
//#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int countBits(int n){
	int cnt = 0;
	while(n > 0){
		cnt += (n&1);
		n >>= 1;
	}
	return cnt;
}

int countBits2(int n){
	int cnt = 0;
	for(int i = 0; i < 31; i++)
		if(n&(1<<i))
			cnt++;
	return cnt;
}

int countBits3(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n = n&(n-1);
	}
	return cnt;
}



int32_t main(){
	
	// Count number of bits
	int n = 9;
	
	cout << countBits(n) << endl;		// O(log(n))
	cout << countBits2(n) << endl;		// O(log(n))
	cout << countBits3(n) << endl;		// Better - O(No of set bits)
	cout << __builtin_popcount(n) << endl;		// Almost O(1) - fastest
	
	// For negative number representation Two's complement is most commonly used
	// Ex -> -1 to gets its binary representation using 2s complement we do as following
	// Representation of 1 => 0000000001
	// Invert bits         => 1111111110
	// Add 1 			   => 1111111111 = -1
	
	// Note  1000000000.. is -2^31
	
	cout << ~n << endl;		// ~x  = -x-1 as it just FLIPS the bits but do not add 1 to get the corresponding -ve value
	
	// To print binary representation of a number
	int x = -1;
	for(int i = 31; i >= 0; i--){
		if(x&(1<<i))
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
	
	// Note - (1<<31) is actually -2^31 due to overflow
	
	
	// Application of Bit Shift operators (<< and >> operators)
	// 1. Setting a bit 
	x = 10;
	x |= (1<<2);
	cout << x << endl;
	
	// Unsetting a bit
	x &= ~(1<<2);
	cout << x << endl;
	
	// Flipping a bit
	x ^= (1<<2);
	cout << x << endl;
	
	// Setting last one bit to 0
	x = 10;
	x = x&(x-1);
	cout << x << endl;
	
	// Above concept is used to check if a number is power of 2 or not 
	// i.e. for all x > 0 if x&(x-1) = 0 => x is power of 2
	
	// Some built in functions by g++ compiler
	x = 10;
	cout << "Inbuilt Functions\n";
	cout << __builtin_clz(x) << endl;		// No of zeroes from left to first 1 bit
	cout << __builtin_ctz(x) << endl;		// No of zeroes at end of a number
	cout << __builtin_popcount(x) << endl;	// No of set bits
	cout << __builtin_parity(x) << endl;	// If no of 1s is even => 0 else 1 
	
	// For long long add ll as suffix in above functions
	
	// Values of least significant bit
	x = 10;
	x = x&(-x);
	cout << x << endl;
	
	// Remainder of a number when divided by a power of 2
	int a = 7, b = 4;
	cout << (a&(b-1)) << endl;
	
	return 0;
}

