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

int col[100], diag[100], diag2[100];
int countWays(int n, int i){
	if(i == n){
		return 1;
	}
	int ans = 0;
	for(int j = 0; j < n; j++){
		if(!col[j] && !diag[i+j] && !diag2[n-1+i-j]){
			col[j] = diag[i+j] = diag2[n-1+i-j] = 1;
			ans += countWays(n,i+1);
			col[j] = diag[i+j] = diag2[n-1+i-j] = 0;
		}
	}
	return ans;
}

vector<int> v;

void printAll(int n, int i){
	if(i == n){
		for(int i = 0;i < n; i++){
			for(int j = 0; j < n; j++){
				if(j == v[i])
					cout << 1;
				else 
					cout << 0;
				cout << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
		return;
	}
	for(int j = 0; j < n; j++){
		if(!col[j] && !diag[i+j] && !diag2[n-1+i-j]){
			col[j] = diag[i+j] = diag2[n-1+i-j] = 1;
			v.PB(j);
			printAll(n,i+1);
			col[j] = diag[i+j] = diag2[n-1+i-j] = 0;
			v.pop_back();
		}
	}
}


int32_t main(){
	int n;
	cin >> n;
	cout << countWays(n,0) << endl;
	
	// Print All Ways
	
	// We Can use 2D array to store positions of queen but lets use 1D array to save space
	
	printAll(n,0);
	 

	return 0;
}

