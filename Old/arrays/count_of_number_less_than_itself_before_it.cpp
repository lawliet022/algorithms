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
	int a[] = {12, 1, 2, 3, 0, 11, 4};
	int n = sizeof(a)/sizeof(int);
	
	// Complexity is O(n^2)
	multiset<int> s;
	for(int i = 0; i < n; i++){
		auto p = s.lower_bound(a[i]);
		cout << distance(s.begin(),p) << " ";			// Distance is 0(n)
		s.insert(a[i]);
	}
	
	// For nlogn use AVL i.e self balancing Binary tree

	return 0;
}

