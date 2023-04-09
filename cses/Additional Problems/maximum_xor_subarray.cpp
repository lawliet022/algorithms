#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);


class node{
public:
	node *bit[2];
	node(){
		for(int i = 0; i < 2; i++){
			bit[i] = NULL;
		}
	}
};

node *head;

void insert(int n){
	node *temp = head;
	for(int i = 31; i >= 0; i--){
		int cur = (n >> i) & 1;
		if(temp->bit[cur] == NULL){
			temp->bit[cur] = new node();
		}
		temp = temp->bit[cur];
	}
}

int getMaxXor(int n){
	node *temp = head;
	int ans = 0;
	for(int i = 31; i >= 0; i--){
		int cur = (n >> i) & 1;
		if(temp->bit[1-cur] != NULL){
			ans += (1<<i);
			temp = temp->bit[1-cur];
		}
		else{
			temp = temp->bit[cur];
		}
	}
	return ans;
}



int32_t main(){
	int n;
	cin >> n;
	
	head = new node();
	insert(0LL);
	
	int pref = 0, ans = 0;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pref ^= x;
		ans = max(ans,getMaxXor(pref));
		insert(pref);
	}
	cout << ans << endl;
	
	
	return 0;
}
