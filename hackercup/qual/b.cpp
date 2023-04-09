#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


void solve(){
	int n;
	cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'A')
			a++;
		else
			b++;
	}
	if(abs(a-b) == 1){
		cout << 'Y';
	}
	else{
		 cout << 'N';
	}
	cout << endl;
}


int32_t main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int t;
	cin >> t;
	int test = 1;
	while(t--){
		cout << "Case #" << test++ << ": ";
		solve();
	}
	
	return 0;
}
