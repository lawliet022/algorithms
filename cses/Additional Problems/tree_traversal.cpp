#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

class node{
public:
	int val;
	node *left, *right;
	node(int x){
		val = x;
		left = right = NULL;
	}
};

const int N = 1e5 + 100;
int pre[N], in[N];
map<int,int> m;

int pos = 0;

node* solve(int l, int r){
	if(l > r)
		return NULL;
	if(l == r){
		node *t = new node(pre[pos++]);
		return t;
	}
	int center = m[pre[pos]];
	node *cur = new node(pre[pos++]);
	cur->left = solve(l,center-1);
	cur->right = solve(center+1,r);
	
	return cur;
}


void post(node *t){
	if(t == NULL)
		return;
	post(t->left);
	post(t->right);
	cout << (t->val) << " " ;
}

int32_t main(){
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> pre[i];
	for(int i = 0; i < n; i++){
		cin >> in[i];
		m[in[i]] = i;
	}
	
	node *tree = solve(0,n-1);
	
	post(tree);
	
	
	return 0;
}
