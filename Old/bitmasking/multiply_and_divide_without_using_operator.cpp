#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}


int32_t main(){
	// Multiply by 9 i.e (1<<3 + 1)
	int x = 10;
	cout << (x<<3) + x << endl;
	
	// Multiply By 6
	cout << (x<<2) + (x<<1) << endl;
	 
	 
	// Divide
	// Method 1 using log
	int a = 30, b = 4;						// a is divident and b is divisor
	cout << exp(log(a)-log(b)) << endl;		// Take (int) for quotient
	
	// Method 2 => using bitmasking, we can represent any quotient using binary
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		if(a >= (b<<i)){						// careful of overflow when b*2^i
			ans += (1<<i);
			a -= (b<<i);
		}
	}
	cout << ans << endl;

	return 0;
}

