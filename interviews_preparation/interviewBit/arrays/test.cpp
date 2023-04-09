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

int32_t main(){
	srand(time(NULL));
	while(1){
		int n;
		//cin >> n;
		n = rand() % 1000000 + 1;
		int ans, me = 0;
		for(int i = n+1; i <= 10000000; i++){
			if(__builtin_popcount(i) == __builtin_popcount(n)){
				ans = i;
				break;
			}
		}
		string s = "";
		int n2 = n;
		while(n2 > 0){
			if(n2&1)
				s += '1';
			else
				s += '0';
			n2 >>= 1;
		}
		reverse(s.begin(),s.end());
		s = "0"+s;
		for(int i = (int)s.size()-1; i > 0; i--)
			if(s[i] == '1' && s[i-1] == '0'){
				swap(s[i],s[i-1]);
				int ct = 0;
				for(int j = i+1; j < (int)s.size(); j++){
					if(s[j] == '1')
						ct++;
					s[j] = '0';
				}
				for(int j = (int)s.size()-1; j > (int)s.size()-1-ct; j--)
					s[j] = '1';
				break;
			}
		for(int i = 0; i < (int)s.size(); i++)
			if(s[i] == '1')
				me = 2*me + 1;
			else
				me = 2*me;
		if(ans != me){
			cout << "Failed\n";
			return 0;
		}
		else{
			cout << "Passed " << n << endl;
		}
	}

	return 0;
}

