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

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string w = to_string(n);
		int mini = n;
		for(int i = 0; i < (int)w.size(); i++){
			string temp = w.substr(0,i) + w.substr(i+1,100);
			mini = min(mini,stoll(temp));
		}
		cout << mini << endl;
	}
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 

	return 0;
}

