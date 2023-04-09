#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


int getMaxXor(int a[], int n){
	int temp = 0;
	for(int i = 30; i >= 0; i--){
		int best = -1, ind = -1;
		for(int j = temp; j < n; j++){
			if( (a[j]&(1<<i)) && a[j] > best){
				best = a[j];
				ind = j;
			}
		}
		if(ind == -1)
			continue;
		swap(a[ind],a[temp]);
		for(int j = 0; j < n; j++){
			if( (j != temp) && (a[j]&(1<<i))){
				a[j] ^= a[temp];
			}
		}
		temp++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans ^= a[i];
	return ans;
}


int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		 cin >> a[i];
	
	cout << getMaxXor(a,n) << endl;
	
	return 0;
}
