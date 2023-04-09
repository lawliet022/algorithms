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



// O(n^2) approach - For addition of each character what is new number of different substrings added
int getpiMax(string s){
	int n = s.size();
	int pi[n+1] = {0};
	int maxi = 0;
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
		maxi = max(pi[i],maxi);
	}
	return maxi;
}


int worst(string s){
	int count = 0;
	int n = s.size();
	for(int i = 1; i <= n; i++){
		set<string> w;
		for(int j = 0; j <= n-i; j++){
			w.insert(s.substr(j,i));
		}
		count += w.size();
	}
	return count;
}



int32_t main(){
	string s = "abaacbaabcaabcaab";
	string w = "a";
	int cnt = 1;
	
	int n = s.size();
	for(int i = 1; i < n; i++){
		string temp = w + s[i];
		w += s[i];
		reverse(temp.begin(),temp.end());
		int pimax = getpiMax(temp);
		cnt += (int)temp.size() - pimax;
	}
	cout << cnt << endl;
	
	cout << worst(s);

	return 0;
}
