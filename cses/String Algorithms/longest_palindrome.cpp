#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int32_t main(){	
	string s;
	cin >> s;
		
	int n = s.size();
	
	
	// Manacher 
	vector<int> d1(n);										// odd
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	
	vector<int> d2(n);										// even
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}

	
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		if(d1[i] * 2 - 1 > odd){
			odd = d1[i] * 2 - 1;
		}
	}
	for(int i = 0; i < n; i++){
		if(d2[i] * 2 > even){
			even = d2[i] * 2;
		}
	}
	
	if(odd >= even){
		for(int i = 0; i < n; i++){
			if(d1[i] * 2 - 1 == odd){
				cout << s.substr(i-d1[i]+1,odd) << endl;
				break;
			}
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(d2[i] * 2 == even){
				cout << s.substr(i-d2[i],even) << endl;
				break;
			}
		}
	}
	cerr << "Time = " << 1.0*clock()/CLOCKS_PER_SEC << endl ; 
	
	
	return 0;
}
