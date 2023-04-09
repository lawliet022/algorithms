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

int ways(int n){
	// base case
	if(n <= 1)
		return 1;
	// rec case
	return ways(n-1) + (n-1)*ways(n-2);			// nth person goes alone or in pair
}

bool gone[1000];
void solve(int rem, int n, vi& v){
	if(rem == 0){
		cout << "{";
		for(int i = 0; i <(int) v.size(); i++){
			if(v[i] == -1){
				if(i < (int)v.size()-1)
					cout << "} {";
				else
					cout << '}';
			}
			else
				cout << v[i];
		}
		cout << endl;
		return;
	}
	int ind;
	for(int i = 1; i <= n; i++){
		if(!gone[i]){
			ind = i;
			break;
		}
	}
	gone[ind] = true;
	v.PB(ind);
	v.PB(-1);
	solve(rem-1,n,v);
	
	v.pop_back();
	if(rem >= 2){
		for(int i = ind+1; i <= n; i++){
			if(!gone[i]){
				gone[i] = true;
				v.PB(i);
				v.PB(-1);
				solve(rem-2,n,v);
				v.pop_back();
				v.pop_back();
				gone[i] = false;
			}
		}
	}
	v.pop_back();
	gone[ind] = false;
}


int32_t main(){
	int n;
	cin >> n;		// No of friends and bikes
	
	cout << ways(n) << endl;
	
	// Printing all ways
	vector<int> v;
	
	solve(n,n,v);


	return 0;
}

