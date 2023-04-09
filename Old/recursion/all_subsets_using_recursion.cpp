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

void allSubset(int a[], vi &v, int ind, int n){
	if(ind == n){
		for(auto x : v)
			cout << x << " ";
		cout << endl;
		return;
	}
	allSubset(a,v,ind+1,n);
	
	v.PB(a[ind]);
	allSubset(a,v,ind+1,n);
	v.pop_back();
	
}

int32_t main(){
	int a[] = {1,2,3,4};
	vi v;
	int n = sizeof(a)/sizeof(int);
	allSubset(a,v,0,n);

	return 0;
}

