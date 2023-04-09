#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	string s;
	cin >> s;
	int ans = 1;
	char ch = s[0];
	int cur = 1;
	for(int i = 1; i < (int)s.size(); i++){
		if(s[i] == ch){			// current char is same as previous char
			cur++;
			ans = max(ans,cur);
		}
		else{
			cur = 1;
			ch = s[i];
		}
	}
	ans = max(ans,cur);
	
	cout << ans << endl;
	
	return 0;
}
