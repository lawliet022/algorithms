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

const int MAX = 105;

bool done[MAX];

bool kPartition(int a[], int n, int k, int seg[], int curSeg, int lastInd, int sumi){
	if(seg[curSeg] == sumi){
		if(curSeg >= k-2){
			return true;
		}
		return kPartition(a,n,k,seg,curSeg+1,n-1,sumi);
	}
	for(int i = lastInd; i >= 0; i--){
		if(done[i])
			continue;
		if(seg[curSeg] + a[i] <= sumi){
			seg[curSeg] += a[i];
			done[i] = true;
			int res = kPartition(a,n,k,seg,curSeg,i,sumi);
			done[i] = false;
			seg[curSeg] -= a[i];
			
			if(res)
				return true;
		}
	}
	return false;
}

bool solve(int a[], int n, int k,int sumi){
	int seg[k+1] = {0};
	seg[0] = a[n-1];
	done[n-1] = true;
	
	return kPartition(a,n,k,seg,0,n-1,sumi);
}


int32_t main(){
	// Looks like it is a NP hard problem and there is no polynomial time solution to this.
	// So we can just try backtracking
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n;
		int a[n], sumi = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sumi += a[i];
		}
		cin >> k;
		if(sumi % k){
			cout << 0 << endl;
			continue;
		}
		if(solve(a,n,k,sumi/k))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	
	return 0;
}

