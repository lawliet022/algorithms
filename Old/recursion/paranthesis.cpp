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


int countParanthesis(int n, int pos, int open,int close){
	if(pos == 2*n){
		return 1;
	}
	int t = 0;
	if(open){
		t = countParanthesis(n,pos+1,open-1,close);
	}
	if(open < close){
		t += countParanthesis(n,pos+1,open,close-1);
	}
	return t;
}

void printAll(int n, int pos, int open,int close, vector<char>& v){
	if(pos == 2*n){
		for(auto x : v)
			cout << x;
		cout << endl;
	}
	if(open){
		v.PB('(');
		printAll(n,pos+1,open-1,close,v);
		v.pop_back();
	}
	if(open < close){
		v.PB(')');
		printAll(n,pos+1,open,close-1,v);
		v.pop_back();
	}
}

int32_t main(){
	int n;
	cin >> n;
	// Count valid paranthesis of 2*n length	
	cout << countParanthesis(n,0,n,n) << endl;		// catalan Number
	
	// Print all valid paranthesis
	vector<char> v;
	printAll(n,0,n,n,v);

	return 0;
}

