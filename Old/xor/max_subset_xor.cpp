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

int getMaxXor(int a[], int n){
	
	int temp = 0;
	for(int i = 30; i >= 0; i--){
		int best = -1, ind = -1;
		for(int j = temp; j < n; j++){
			if( (a[j]&(1<<i)) && a[j] > best){
				best = a[j];
				ind = j;
			}
		}
		if(ind == -1)
			continue;
		swap(a[ind],a[temp]);
		for(int j = 0; j < n; j++){
			if( (j != temp) && (a[j]&(1<<i))){
				a[j] ^= a[temp];
			}
		}
		temp++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans ^= a[i];
	return ans;
}


int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    srand(time(NULL));
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int maxi = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            maxi = max(maxi,a[i]);
        }
        // Checking all possible subsets in O(n*2^n)
        for(int i = 1; i < (1<<n); i++){
            int x = 0;
            for(int j = n; j >= 0; j--){
                if(i&(1<<j))
                    x ^= a[j];
            }
            maxi = max(maxi,x);
        }
        
        int maxi2 = getMaxXor(a,n);			// Gaussian elimination approach - O(n)
        
        cout << maxi << " " << maxi2 << endl;
    }
    



	return 0;
}
