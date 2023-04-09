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

int maxxor(int x){
	trie* node = head;
	int ans = 0;
	
	for(int i = 30; i >= 0; i--){
		int curbit = (x>>i)&1;
		if(node->bit[curbit^1] != NULL && node->bit[curbit^1]->count > 0){
			ans += (1<<i);
			node = node->bit[curbit^1];
		}
		else{
			node = node->bit[curbit];
		}
	}
	return ans;
}

int minxor(int x){
	trie* node = head;
	int ans = 0;
	
	for(int i = 30; i >= 0; i--){
		int curbit = (x>>i)&1;
		if(node->bit[curbit] != NULL && node->bit[curbit]->count > 0){
			ans += (1<<i);
			node = node->bit[curbit];
		}
		else{
			node = node->bit[curbit^1];
		}
	}
	return ans;
}

int32_t main(){
	srand(time(NULL));
	head = new trie();
	int a[] = {11,4,15,64,34,13,56,9,31,19,45,32,73};
	int n = sizeof(a)/sizeof(int);
	
	int temp = 0, maxi = 0;
	for(int i = 0; i < n; i++){
		temp ^= a[i];
		insert(temp);
		maxi = max(maxi, maxxor(temp));
	}
	
	cout << maxi << endl;
	
	// Brute force
	int ans = 0;
	for(int i = 0; i < n; i++){
		int temp = a[i];
		ans = max(ans,temp);
		for(int j = i+1; j < n; j++){
			temp = temp^a[j];
			ans = max(ans,temp);
		}
	}
	cout << ans;

	return 0;
}
