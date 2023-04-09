#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

// Lesson learnt - Always make modulo as const.. because compiler handles modulo by const very well and fast
// Spent like 3-4 hours for this TLE bug :/

// Learnt matrix multiplication optimisation when there are lot of 0's in matrix

// Useful resources - https://blog.csdn.net/accelerator_/article/details/38468193
// and one more chinease blog with a matrix recurrance photo.. google it

// matrix size max can be 150*150 for base = 6 i.e. previous 25 states with 6 last digit states

int a[155][155], b[155][155];

int base, score;

int dp[50][7];

int solve(int val, int last){
	if(val == 0){
		if(last){
			return 1;
		}
		else
			return 0;
	}
	int &ans = dp[val][last];
	if(ans != -1)
		return ans;
	
	ans = 0;
	
	for(int i = 0; i < base; i++){
		if(last == i)
			continue;
		if(val-(last-i)*(last-i) >= 0){
			ans += solve(val-(last-i)*(last-i),i);
		}
	}
	return ans;
}

const int mod = 1LL<<32;
int res[200][200];
	
void matmul(int b[][155], int a[][155]){
	int d = (base-1)*(base-1)*base;
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++)
			res[i][j] = 0;
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++){
			if(b[j][i] == 0)
				continue;
			for(int k = 0; k < d; k++){
				res[j][k] = (res[j][k] + b[j][i]*a[i][k] % mod) % mod;
			}
		}
	for(int i = 0; i < d; i++)
		for(int j = 0; j < d; j++){
			b[i][j] = res[i][j];
			if(b[i][j] < 0)
				b[i][j] += mod;
		}
}


void matpow(int n){
	if(n == 0)
		return;
	matpow(n>>1);
	matmul(b,b);
	if(n&1){
		matmul(b,a);
	}
	//while(n > 0){
		//if(n&1){
			//matmul(b,a);
		//}
		//n >>= 1;
		//matmul(a,a);
	//}
}



int32_t main(){
	
	int t;
	cin >> t;
	for(int test = 1; test <= t; test++){
		for(int i = 0; i < 50; i++)
			for(int j = 0; j < 7; j++)
				dp[i][j] = -1;
		cin >> base >> score;
		
		// Initialising the recurrence matrix
		for(int i = 0; i <= 152; i++)
			for(int j = 0; j <= 152; j++)
				a[i][j] = 0;
		
		int cnt = (base-1)*(base-1)*base;
		for(int i = 0; i < cnt-base; i++){
			a[i][i+base] = 1;
		}
		for(int i = cnt-base; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				if(i % base == j % base)
					continue;
				if((i/base+2)-(j/base+1) == (i%base-j%base)*(i%base-j%base))
					a[i][j] = 1;
			}
		}
		
		int x[cnt];
		for(int i = 0; i < cnt; i++){
			int p = i / base;
			int q = i % base;
			x[i] = solve(p+1,q);
		}
		
		if(score <= (base-1)*(base-1)){
			int ans = 0;
			for(int i = base*(score-1); i < base*(score); i++)
				ans += x[i];
			ans %= mod;
			cout << "Case " << test << ": " << ans << endl;
		}
		else{
			for(int i = 0; i < 152; i++)
				for(int j = 0; j < 152; j++)
					b[i][j] = (i == j ? 1 : 0);
			int req = score - (base-1)*(base-1);
			matpow(req);
			
			int ans = 0;
			for(int i = cnt-base; i < cnt; i++){
				for(int j = 0; j < cnt; j++){
					ans += b[i][j]*x[j];
					ans %= mod;
				}
			}
			if(ans < 0)
				ans += mod;
			cout << "Case " << test << ": " << ans << endl;
		}		
	}
	return 0;
}


// OR using matrix snippet
//#include<bits/stdc++.h>
//#define PB push_back
//#define MP make_pair
//#define F first
//#define S second
//#define MOD	1000000007
//#define int	long long
//#define pii pair<int,int> 
//#define vi vector<int>
//using namespace std;

//int a[155][155], b[155][155];

//int base, score;

//int dp[50][7];

//int solve(int val, int last){
	//if(val == 0){
		//if(last){
			//return 1;
		//}
		//else
			//return 0;
	//}
	//int &ans = dp[val][last];
	//if(ans != -1)
		//return ans;
	
	//ans = 0;
	
	//for(int i = 0; i < base; i++){
		//if(last == i)
			//continue;
		//if(val-(last-i)*(last-i) >= 0){
			//ans += solve(val-(last-i)*(last-i),i);
		//}
	//}
	//return ans;
//}

//const int mod = 1LL<<32;
//int res[155][155];
//const int N = 155;
//int n;
//struct Mat {
    //int v[N][N];

    //Mat() {
	//memset(v, 0, sizeof(v));
    //}

    //void init() {
	//memset(v, 0, sizeof(v));
    //}

    //void init_one() {
	//memset(v, 0, sizeof(v));
	//for (int i = 0; i < n; i++)
	    //v[i][i] = 1;
    //}

    //Mat operator * (Mat c) {
	//Mat ans;
	//for (int k = 0; k < n; k++) {
	    //for (int i = 0; i < n; i++) {
		//if (!v[i][k]) continue;
			//for (int j = 0; j < n; j++){
				//ans.v[i][j] = (ans.v[i][j] + v[i][k] * c.v[k][j] % mod) % mod;
			//}
	    //}
	//}
	//return ans;
    //}
//} B;

//Mat pow_mod(Mat x, int k) {
    //Mat ans;
    //ans.init_one();
    //while (k) {
		//if (k&1) ans = ans * x;
		//x = x * x;
		//k >>= 1;
    //}
    //return ans;
//}




//signed main(){
	
	//int t;
	//scanf("%lld", &t);

	//for(int test = 1; test <= t; test++){

		//for(int i = 0; i < 50; i++)
			//for(int j = 0; j < 7; j++)
				//dp[i][j] = -1;

		//scanf("%lld %lld", &base, &score);
		//n = (base-1)*(base-1)*base;
		
		//// Initialising the recurrence matrix
		//B.init();
		//int cnt = n;
		//for(int i = 0; i < cnt-base; i++){
			//B.v[i][i+base] = 1;
		//}
		//for(int i = cnt-base; i < cnt; i++){
			//for(int j = 0; j < cnt; j++){
				//if(i % base == j % base)
					//continue;
				//if((i/base+2)-(j/base+1) == (i%base-j%base)*(i%base-j%base))
					//B.v[i][j] = 1;
			//}
		//}
		
		//int x[cnt];
		//for(int i = 0; i < cnt; i++){
			//int p = i / base;
			//int q = i % base;
			//x[i] = solve(p+1,q);
		//}
		
		//if(score <= (base-1)*(base-1)){
			//int ans = 0;
			//for(int i = base*(score-1); i < base*(score); i++)
				//ans += x[i];
			//ans %= mod;
			//printf("Case %lld: %lld\n" , test, ans);
		//}
		//else{
			//int req = score - (base-1)*(base-1);
			//B = pow_mod(B,req);
			//int ans = 0;
			//for(int i = cnt-base; i < cnt; i++){
				//for(int j = 0; j < cnt; j++){
					//ans += B.v[i][j]*x[j];
					//ans %= mod;
				//}
			//}
			//if(ans < 0)
				//ans += mod;
			//printf("Case %lld: %lld\n" , test, ans);
			//cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
		//}		
	//}
	//return 0;
//}






