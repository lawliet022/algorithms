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
	int a[] = {-2,12,7,3,1,5,4,7,10,20};
	int target = 5;
	int n = sizeof(a)/sizeof(int);
	
	int l = 0, r = n - 1;
	sort(a,a+n);
	
	while(l < r){
		if(a[l]+a[r] == target){
			cout << "Found " << a[l] << " and " << a[r] << endl;
			//	modify accordingly to print all distinct pairs
			return 0;
		}
		if(a[l] + a[r] > target){
			r--;
		}
		else
			l++;
	}
	cout << "Not found\n";

	return 0;
}

