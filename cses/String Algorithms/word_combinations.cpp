#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MOD = (int)1e9 + 7;
const double PI = acos(-1.0);

class node{
public:
	bool isEnd;
	node *next[26];
	node(){
		isEnd = false;
		for(int i = 0; i < 26; i++)
			next[i] = NULL;
	}
};

node *head;

void insert(string &s){
	int n = s.size();
	node *temp = head;
	for(int i = 0; i < n; i++){
		if(temp->next[s[i]-'a'] == NULL){
			temp->next[s[i]-'a'] = new node();
		}
		temp = temp->next[s[i]-'a'];
	}
	temp->isEnd = true;
}



int32_t main(){
	string s;
	cin >> s;
	int m;
	cin >> m;
	head = new node();
	for(int i = 0; i < m; i++){
		string t;
		cin >> t;
		reverse(t.begin(),t.end());
		insert(t);
	}
	
	int n = s.size();
	int dp[n+1] = {0};
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		node *temp = head;
		for(int j = i; j >= 1; j--){
			if(temp->next[s[j-1]-'a'] == NULL){
				break;
			}
			temp = temp->next[s[j-1]-'a'];
			if(temp->isEnd){
				dp[i] += dp[j-1];
				dp[i] %= MOD;
			}
		} 
	}
	
	cout << dp[n] << endl;
	
	
	return 0;
}
