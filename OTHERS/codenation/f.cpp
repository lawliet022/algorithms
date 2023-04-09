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
	string s;
	cin >> s;
	int n = s.size();
	
	vector<int> d1(n);
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
	//for(int i = 0; i < n; i++)
		//cout << d1[i] << " ";
	//cout << endl;
	
	int maxi1[n+1];
	for(int i = 0; i < n; i++)
		maxi1[i] = 1;
	
	for(int i = 0; i < n; i++){
		int p = d1[i];
		if(p > 1){
			maxi1[i+(2*p-1)/2] = max(maxi1[i+(2*p-1)/2], 2*p-1);
		}
	}
	for(int i = n-2; i >= 0; i--){
		if(maxi1[i+1] > maxi1[i]){
			maxi1[i] = max(maxi1[i],maxi1[i+1]-2);
		}
	}
	//for(int i = 0; i < n; i++)
		//cout << maxi1[i] << " ";
		
	// ---- reverse side
	
	int maxi2[n+1];
	for(int i = 0; i < n; i++)
		maxi2[i] = 1;
	
	for(int i = n-1; i >= 0; i--){
		int p = d1[i];
		if(p > 1){
			maxi2[i-(2*p-1)/2] = max(maxi2[i-(2*p-1)/2], 2*p-1);
		}
	}
	for(int i = 1; i < n; i++){
		if(maxi2[i-1] > maxi2[i]){
			maxi2[i] = max(maxi2[i],maxi2[i-1]-2);
		}
	}
	//cout << endl;
	//for(int i = 0; i < n; i++)
		//cout << maxi2[i] << " ";
		
	int pref[n+1] = {0};
	pref[0] = maxi1[0];
	
	int suff[n+1] = {0};
	suff[n-1] = maxi2[n-1];

	for(int i = 1; i < n; i++)
		pref[i] = max(pref[i-1],maxi1[i]);
	
	for(int i = n-2; i >= 0; i--)
		suff[i] = max(suff[i+1],maxi2[i]);
		
	int ans = 1;
	for(int i = 1; i < n-1; i++){
		ans = max(ans,pref[i]*suff[i+1]);
	}
	cout << ans << endl;
	return 0;
}

