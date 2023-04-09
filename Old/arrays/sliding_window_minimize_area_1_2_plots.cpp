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
	// Buying one empty plot of given area with minimum number of elements
	int a[] = {1,4,3,2,5,17,9,1,1};
	int n = sizeof(a)/sizeof(int);
	
	int l = 0, r = 0, sumi = 0, target = 10;
	int x = 0, y = 1e9, flag = 0;
	
	while(r < n){
		sumi += a[r++];
		while(sumi > target){
			sumi -= a[l++];
		}
		if(sumi == target){
			if(r-l < (y-x+1)){
				x = l;
				y = r-1;
			}
			sumi -= a[l++];
			flag = 1;
		}
	}
	if(flag)
		cout << "Found in " << x << " " << y << endl;
	else
		cout << "No plot found of given area\n";
		
	// Buying 2 empty plots of given area with minimum number of elements
	// Area = 12 Greedy fails here	1 1 1 1 1 1 1 2 2 1 4 1 2 5 2 5 4 1 1 1 1 1 1 1 1 2 2 1
	// because picking 1 plot of size 3 we cannot pick 2 plots of size 4 each
	
	int b[] = {1,1,1,1,1,1,1,2,2,1,4,1,2,5,2,5,4,1,1,1,1,1,1,1,1,2,2,1};
	n = sizeof(b)/sizeof(int);
	int p[n] = {0}, q[n] = {0};
	for(int i = 0; i < n; i++)
		p[i] = q[i] = INT_MAX;
	
	l = 0, r = 0, sumi = 0, target = 12;
	x = 0, y = 1e9, flag = 0;
	
	while(r < n){
		sumi += b[r++];
		while(sumi > target){
			sumi -= b[l++];
		}
		if(sumi == target){
			if(r-l < (y-x+1)){
				x = l;
				y = r-1;
			}
			sumi -= b[l++];
		}
		p[r-1] = min(p[r-1],y-x+1);
	}
	
	l = n-1, r = n-1, sumi = 0, target = 12;
	x = 0, y = 1e9, flag = 0;
	
	while(r >= 0){
		sumi += b[r--];
		while(sumi > target){
			sumi -= b[l--];
		}
		if(sumi == target){
			if(l-r < (y-x+1)){
				x = r+1;
				y = l;
				sumi -= b[l--];
			}
		}
		q[r+1] = min(q[r+1],y-x+1);
	}
	//for(int i = 0; i < n; i++)
		//cout << p[i] << " ";
	//cout << endl;
	
	//for(int i = 0; i < n; i++)
		//cout << q[i] << " ";
	//cout << endl;
		
	int best = INT_MAX;
	for(int i = 0; i < n-1; i++){
		if(p[i] + q[i+1] < best){
			best = p[i] + q[i+1];
			cout << "best = " << best << " at " << i << endl;
		}
	}
	cout << best << endl;
	
	

	return 0;
}

