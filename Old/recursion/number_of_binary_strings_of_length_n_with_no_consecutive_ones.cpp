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

int getNoOfWays(int n, int cur, int prev){
	// base case
	if(cur == n)
		return 1;
		
	// rec case
	if(prev == 0){
		int a = getNoOfWays(n,cur+1,0);
		int b = getNoOfWays(n,cur+1,1);
		return a+b;
	}
	else{
		return getNoOfWays(n,cur+1,0);
	}
}

void PrintAll(string& s, int n, int prev){
	if((int)s.size() == n){
		cout << s << endl;
		return;
	}
	if(prev == 0){
		s += '0';
		PrintAll(s,n,0);
		s.back() = '1';
		PrintAll(s,n,1);
		s.pop_back();
	}
	else{
		s += '0';
		PrintAll(s,n,0);
		s.pop_back();				// or s.erase(s.end()-1);
	}
}


int32_t main(){
	int n;
	cin >> n;
	
	cout << getNoOfWays(n,0,0) << endl;
	
	// Print all possible strings
	string s = "";
	PrintAll(s,n,0);

	return 0;
}

