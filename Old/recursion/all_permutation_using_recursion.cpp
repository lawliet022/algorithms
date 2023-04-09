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


#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << " = " << a << "]" << " ";
	err(++it, args...);
}

bool vis[100];
void allPermutations(string s, string t){
	if(t.size() == s.size()){
		cout << t << endl;
		return;
	}
	for(int i = 0; i < (int)s.size(); i++){
		if(vis[i])
			continue;
		t += s[i];
		vis[i] = 1;
		allPermutations(s,t);
		t.pop_back();
		vis[i] = 0;
	}
}

void allPermutations2(string s, int i){
	if(i == (int)s.size()){
		cout << s << endl;
		return;
	}
	for(int j = i; j < (int)s.size(); j++){
		swap(s[i],s[j]);
		allPermutations2(s,i+1);
		swap(s[i],s[j]);
	}
}

int32_t main(){
	
	string s = "ABC";
	string t = "";
	allPermutations(s,t);
	
	cout << endl << endl;
	allPermutations2(s,0);
	
	
	return 0;
}

