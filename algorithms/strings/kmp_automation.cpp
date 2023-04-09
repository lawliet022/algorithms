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

vi prefixFunc(string s){
	int n = s.size();
	vi pi(n+1,0);
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}


//	O(26*n^2)
void compute_automaton(string s, vector<vector<int>>& aut){
	s += '#';
	int n = s.size();
	vi pi = prefixFunc(s);
	aut.assign(n,vector<int>(26));
	for(int i = 0; i < n; i++){
		for(int c = 0; c < 26; c++){
			int j = i;
			while(j > 0 && 'a' + c != s[j])
				j = pi[j-1];
			if('a' + c == s[j])
				j++;
			aut[i][c] = j;
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			cout << aut[i][j] << " ";
		}
		cout << endl;
	}
}


// O(26*n)
void compute_automaton2(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vi pi = prefixFunc(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			cout << aut[i][j] << " ";
		}
		cout << endl;
	}
	
}

int32_t main(){
	string s = "aabca";
	vector<vector<int>> aut;
	compute_automaton(s,aut);
	cout << endl << endl;
	compute_automaton2(s,aut);
	
	return 0;
}
