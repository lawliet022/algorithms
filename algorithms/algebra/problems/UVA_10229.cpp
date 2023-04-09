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

int mod;

void matmul(int a[2][2], int b[2][2]){
	int res[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;
			for(int k = 0; k < 2; k++){
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= mod;
			}
		}
	}
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = res[i][j];
}

void matpow(int a[2][2], int res[2][2], int n){
	if(n == 0)
		return;
	matpow(a,res,n>>1);
	if(n&1){
		matmul(res,res);
		matmul(res,a);
	}
	else{
		matmul(res,res);
	}
}


int32_t main(){
	int n, m;
	while(cin >> n >> m){
		int a[2][2] = {0,1,1,1};			// fib recurrance matrix
		int res[2][2] = {1,0,0,1};			// identity matrix
		mod = (1<<m);
		matpow(a,res,n);
		cout << res[1][0] << endl;
	}

	return 0;
}

