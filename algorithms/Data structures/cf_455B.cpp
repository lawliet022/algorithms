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
	trie* c[30];
};

trie* head;

void insert(string s){
	trie* node = head;
	for(int i = 0; i < (int)s.size(); i++){
		if(node->c[s[i]-97] == NULL){
			node->c[s[i]-97] = new trie();
		}
		node = node->c[s[i]-97];
	}
}

pair<int,int> solve(trie* temp){
	int flag = 0;
	pair<int,int> w = {0,0}, q;
	for(int i = 0; i < 26; i++){
		if(temp->c[i] != NULL){
			q = solve(temp->c[i]);
			w.F |= !(q.F);	w.S |= !(q.S);
			flag = 1;
		}
	}
	if(!flag){
		return {0,1};
	}
	else{
		return w;
	}
}


int32_t main(){
	int n, k;
	cin >> n >> k;
	head = new trie();
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		insert(s);
	}
	pair<int,int> p = solve(head);
	
	if(p.F == 0){
		cout << "Second";
	}
	else if(p.F == 1 && p.S == 1){
		cout << "First";
	}
	else{
		if(k%2){
			cout << "First";
		}
		else{
			cout << "Second";
		}
	}

	return 0;
}
