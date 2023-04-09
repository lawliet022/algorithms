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

// Finding a subarray with a given sum

int32_t main(){
	int a[] = {1,5,7,2,4,10,3,6};
	int n = sizeof(a)/sizeof(int);
	
	
	// Applicable only if no negative number
	int l = 0, r = 0, sumi = 0, target = 13;
	bool flag = 0;
	while(r < n){
		sumi += a[r++];
		while(sumi > target){
			sumi -= a[l++];
		}
		if(sumi == target){
			cout << "Found b/w " << l << " " << r-1 << endl;
			flag = 1;
			break;
		}
	}
	if(!flag)
		cout << "Not found\n";
	
	
	// If negative Numbers
	int b[] = {16,-5,4,-2,-5,10,6};
	n = sizeof(b)/sizeof(int);
	
	flag = 0;
	target = -3;
	
	sumi = 0;
	unordered_map<int,int> m;
	for(int i = 0; i < n; i++){
		sumi += b[i];
		if(sumi == target){
			cout << "Found between 0 and " << i << endl;
			flag = 1;
			break;
		}
		else if(m.count(sumi-target) > 0){
			cout << "Found between " << m[sumi-target]+1 << " " << i << endl;
			flag = 1;
			break;
		}
		m[sumi] = i;
	}
	if(!flag){
		cout << "Not found\n";
	}


	return 0;
}

