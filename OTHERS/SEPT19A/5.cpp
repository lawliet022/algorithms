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


int naresh(long long N, long long P) { 
    int s = 0;
    for (int i = 1; i <= sqrt(N-P); i++){ 
         if((N-P) % i == 0){
			if(i > P)
				s++;
			if((N-P)/i != i && (N-P)/i > P)
				s++;
		 }
    }
    return s;
}


int brute(int n, int p){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == p)
			cnt++;
	}
	return cnt;
}

int32_t main(){
	srand(time(NULL));
	while(1){
		int n, p;
		//cin >> n >> p;
		n = rand() % 10000000 + 10;
		p = rand() % 10000000 + 5;
		if(n == p)
			continue;
		if(p > n)
			swap(p,n);
		
		int ans1 = naresh(n,p);
		int ans2 = brute(n,p);
		if(ans1 != ans2){
			cout << "Failed\n";
			cout << "n = " << n << " p = " << p << endl;
			cout << ans1 << " " << ans2 << endl;
			return 0;
		}
		else
			cout << "Passed\n";
	}

	return 0;
}

