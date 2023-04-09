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

bool isSorted(int a[], int n, int ind){
	if(ind == n-1){
		return true;
	}
	if(a[ind] <= a[ind+1]){
		return isSorted(a,n,ind+1);
	}
	else
		return false;
}

int32_t main(){
	int a[] = {1,5,7,11,34,34,53,88,92};
	int n = sizeof(a)/sizeof(int);
	
	if(isSorted(a,n,0))	
		cout << "Sorted\n";
	else
		cout << "Not Sorted\n";
	
	return 0;
}

