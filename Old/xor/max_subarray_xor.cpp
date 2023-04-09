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

struct trie{
	trie* next[2];
};


void insert(trie* head, int x){
	for(int i = 30; i >= 0; i--){
		int bit = (x>>i)&1;
		if(head->next[bit] == NULL){
			head->next[bit] = new trie();
		}
		head = head->next[bit];
	}
}

int getMaxXor(trie* head, int val){
	int ans = 0;
	for(int i = 30; i >= 0; i--){
		int bit = (val>>i)&1;
		if(head->next[1-bit] == NULL){
			ans *= 2;
			head = head->next[bit];
		}
		else{
			ans = ans*2 + 1;			//Or just add (1<<i) to ans and not do anyting in if() case
			head = head->next[1-bit];
		}
	}
	return ans;
}

int brute(int a[], int n){
	int maxi = 0;
	for(int i = 1;i <= n; i++){
		int temp = 0;
		for(int j = i; j <= n; j++){
			temp ^= a[j];
			maxi = max(maxi,temp);
		}
		
	}
	return maxi;
}

int32_t main(){
	int t;
	cin >> t;

	while(t--){
		trie* head = NULL;
		head = new trie();
	
		int n;
		cin >> n;

		int a[n+1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}			
		int pref[n+1] = {0};
		pref[1] = a[1];
		for(int i = 2; i <= n; i++)
			pref[i] = pref[i-1]^a[i];
		
		insert(head,0);
		int maxi = 0;
		for(int i = 1; i <= n; i++){
			maxi = max(maxi,getMaxXor(head,pref[i]));
			insert(head,pref[i]);
		}
		cout << maxi << endl;
	}

	return 0;
}

