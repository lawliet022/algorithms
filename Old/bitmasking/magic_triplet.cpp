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

// 	https://practice.geeksforgeeks.org/problems/magic-triplets/0

int n;

void rangeUpdate(int b[], int l, int val){
	for(int i = l; i <= n; i = (i|(i+1))){
		b[i] += val;
	}
}

int getVal1(int b[], int l){
	int val = 0;
	for(int i = l; i >= 0; i = (i&(i+1))-1){
		val += b[i];
	}
	return val;
}

int getVal2(int b[], int l){
	return getVal1(b,n) - getVal1(b,l);
}

void compress(int a[], int n){
	vector<pii> b(n);
	for(int i = 0; i < n; i++)
		b[i] = {a[i],i};
	sort(b.begin(),b.end());
	int prev = -1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(b[i].F == prev){
			a[b[i].S] = cnt;
		}
		else{
			cnt++;
			a[b[i].S] = cnt;
			prev = b[i].F;
		}
	}
}

int32_t main(){
	//ios::sync_with_stdio(0);
    //cin.tie(NULL);
    // Last submission was n^2 approach where for every element i was iterating over left and right to count of numbers less and greater resp..
    // We can do this in O(nlogn) using BIT with compression .. Final Complexity is O(nlogn)..
	// Without compression its O(nlog(MAXVAL))
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
            
        int bit1[n+2] = {0}, bit2[n+2] = {0};
        compress(a,n);
		
        int pref[n+1], suff[n+1];
        pref[0] = 0;
        
        rangeUpdate(bit1,a[0],1);
		for(int i = 1; i < n; i++){
			pref[i] = getVal1(bit1,a[i]-1);
			rangeUpdate(bit1,a[i],1);
		}
		
		suff[n-1] = 0;
        
		rangeUpdate(bit2,a[n-1],1);
		for(int i = n-2; i >= 0; i--){
			suff[i] = getVal2(bit2,a[i]);
			rangeUpdate(bit2,a[i],1);
		}
		//for(int i = 0; i < n; i++){
			//cout << pref[i] << " ";
		//}
		//cout << endl;
		//for(int i = 0; i < n; i++){
			//cout << suff[i] << " ";
		//}
		
		//cout << endl;
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += pref[i]*suff[i];
		}
		cout << ans << endl;
    }


	return 0;
}
