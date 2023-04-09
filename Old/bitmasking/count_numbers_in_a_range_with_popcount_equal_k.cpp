#include<bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int k;
vector<int> dig;
int dp[50][50][2];

int getcount(int pos, int c, int f){
	if(pos == (int)dig.size()){
		if(c == k)
			return 1;
		return 0;
	}
	if(c > k)
		return 0;
	int &ans = dp[pos][c][f];
	if(ans)
		return ans;

	int maxi = -1;
	if(f == 0){
		maxi = dig[pos];
	}
	else
		maxi = 1;
	for(int i = 0; i <= maxi; i++){
		int nf = f;
		if(f == 0 && i < maxi)
			nf = 1;
		if(i == 1)
			ans += getcount(pos+1,c+1,nf);
		else
			ans += getcount(pos+1,c,nf);
	}
	return ans;
}

vector<int> getBinary(int n){
	vi v;
	while(n > 0){
		if(n&1)
			v.PB(1);
		else
			v.PB(0);
		n >>= 1;
	}
	reverse(v.begin(),v.end());
	return v;
}

int solve(int x){
	dig.resize(0);
	dig.clear();
	
	dig = getBinary(x);
	
	return getcount(0,0,0);
}



int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

//int random2(){
	//int x = rand()%10000000;
	//x = x << 12;
	//x += rand()%100000000;
	//return x;
//}



int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	int n;
	cin >> n;
	k = __builtin_popcountll(n);					
	cout << solve(n-1) << endl;
	
	// --------- OR ------------
	
	int ans = 0, used = 0;
	for(int i = 45; i >= 0; i--){
		if(n&(1LL<<i)){
			int places = i;
			int bits = k - used;
			if(bits > places)
				continue;		
			ans += C(places,bits);
			used++;
		}
	}
	cout << ans << endl;
    	

	return 0;
}
