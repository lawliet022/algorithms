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


void replacePi(string& s, int cur){
	if(cur >= (int)s.size()-1){
		return;
	}
	if(s[cur] == 'p' && s[cur+1] == 'i'){
		s += "  ";
		for(int i = (int)s.size()-1; i >= cur; i--)
			s[i+2] = s[i];
		s[cur] = '3';
		s[cur+1] = '.';
		s[cur+2] = '1';
		s[cur+3] = '4';
		replacePi(s,cur+4);
	}
	else
		replacePi(s,cur+1);
}



int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		replacePi(s,0);
		cout << s << endl;
	}

	return 0;
}

