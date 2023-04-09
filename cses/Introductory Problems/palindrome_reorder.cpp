#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){
	string s;
	cin >> s;
	int cnt[26] = {0};
	for(auto x : s){
		cnt[x-'A']++;
	}
	int odd = 0, pos = -1;
	for(int i = 0; i < 26; i++){
		if(cnt[i] % 2){
			odd++;
			pos = i;
		}
	}
	if(odd > 1){
		cout << "NO SOLUTION";
		return 0;
	}
	for(int i = 0; i < 26; i++){
		if(i == pos)
			continue;
		for(int j = 0; j < cnt[i] / 2; j++){
			cout << char('A'+i);
		}
	}
	if(pos != -1){
		for(int i = 0; i < cnt[pos]; i++){
			cout << char('A' + pos);
		}
	}
	for(int i = 25; i >= 0; i--){
		if(i == pos)
			continue;
		for(int j = 0; j < cnt[i] / 2; j++){
			cout << char('A'+i);
		}
	}
	
	
	return 0;
}
