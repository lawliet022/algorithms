#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		int p[30] = {0}, q[30] = {0};
		for(auto x : a){
			p[x-'a']++;
		}
		for(auto x : b){
			q[x-'a']++;
		}
		string ans = "";
		for(int i = 0; i < 26; i++){
			if(q[i] && p[i] == 0){
				ans += char('a' + i);
			}
		}
		if(ans.size()){
			cout << ans << endl;
		}
		else{
			cout << -1 << endl;
		}
		
	}
	
	return 0;
}
