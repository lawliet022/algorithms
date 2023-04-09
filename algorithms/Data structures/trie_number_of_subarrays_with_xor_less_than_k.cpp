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

struct trie{
	trie* bit[2];
	int count = 0;
};

trie* head;

void insert(int x){
	trie* node = head;
	
	for(int i = 30; i >= 0; i--){
		int curbit = (x>>i)&1;
		if(node->bit[curbit] == NULL){
			node->bit[curbit] = new trie();
		}
		node = node->bit[curbit];
		node->count++;
	}
}

void remove(int x){
	trie *node = head;
	for(int i = 30; i >= 0; i--){
		int curbit = (x>>i)&1;
		node = node->bit[curbit];
		node->count--;
	}
}

int solve(int x, int k){
	trie* node = head;
	int ans = 0;
	
	for(int i = 30; i >= 0; i--){
		int curbit = (x>>i)&1;
		int kbit = (k>>i)&1;
		if(kbit == 0){
			//cout << "kbit = " << kbit << endl;
			if(node->bit[curbit] == NULL || node->bit[curbit]->count == 0)
				return ans;
			else{
				node = node->bit[curbit];
			}
		}
		else{
			if(node->bit[curbit] != NULL && node->bit[curbit]->count > 0)
				ans += node->bit[curbit]->count;
			if(node->bit[curbit^1] == NULL)
				return ans;
			node = node->bit[curbit^1];
		}
	}
	return ans;
}



int32_t main(){
	head = new trie();
	//insert(0);
	
	int a[] = {11,4,15,64,34,13,0,11,13,7,22,56,9,31,19,45,32,73,12,54,34,57,43,23};
	int n = sizeof(a)/sizeof(int);
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	int k = 20;
	int ans = 0, temp = 0;
	for(int i = 0; i < n; i++){
		temp ^= a[i];
		if(temp < k)
			ans++;
		if(i){
			ans += solve(temp,k);
		}
		//else{
			//if(a[i] < k)
				//ans++;
		//}
		insert(temp);
	}
	
	cout << ans << endl;
	
	// Brute force
	int ans2 = 0;
	for(int i = 0; i < n; i++){
		int temp = a[i];
		if(temp < k)	ans2++;
		for(int j = i+1; j < n; j++){
			temp = temp^a[j];
			if(temp < k)	ans2++;
		}
	}
	cout << ans2;


	return 0;
}
