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

int n;

void brute(int a[], int perm[], int NOT){
	for(int i = 0; i < NOT; i++){
		int b[n];
		for(int j = 0; j < n; j++){
			b[j] = a[perm[j]];
		}
		for(int j = 0; j < n; j++){
			a[j] = b[j];
		}
	}
}

void binpow(int perm[], int NOT, int ans[]){
	int temp[n];
	for(int i = 0; i < n; i++)
		temp[i] = perm[i];
	while(NOT > 0){
		if(NOT&1){
			int temp2[n];
			for(int j = 0; j < n; j++)
				temp2[j] = ans[temp[j]];
			for(int j = 0; j < n; j++)
				ans[j] = temp2[j];
		}
		NOT >>= 1;
		int temp2[n];
		for(int j = 0; j < n; j++)
			temp2[j] = temp[temp[j]];
		for(int j = 0; j < n; j++)
			temp[j] = temp2[j];
	}
}



int32_t main(){
	int a[] = {11,3,15,2,14,7,13};
	int perm[] = {1,4,0,3,2,6,5};
	n = 7;
	
	int NOT = 10000;				// Number of times permutations to apply
	
	int ans[n];		
	for(int i = 0; i < n; i++)
		ans[i] = i;
	
	binpow(perm,NOT,ans);
	
	// Now ans has final permutaion
	for(int i = 0; i < n; i++)
		cout << a[ans[i]] << " ";
		
	cout << endl;
	
	
	brute(a,perm,NOT);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}

