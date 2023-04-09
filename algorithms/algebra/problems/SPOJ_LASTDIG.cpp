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

int getLastDig(int a, int b){
	if(a == 0)
		return 0;
	int ans = 1;
	while(b > 0){
		if(b&1){
			ans = (ans*a)%10;
		}
		a = a*a % 10;
		b >>= 1;
	}
	return ans;
}


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << getLastDig(a,b) << endl;
	}

	return 0;
}

