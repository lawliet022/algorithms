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


int xorring(int n){
    int ans = 0;
    for(int i = 0; i < 31; i++){
        int cnt = (1<<i) * ((n+1)/(1<<(i+1)));
        int temp = max((n+1) - ((n+1)/(1<<(i+1)))*(1<<(i+1)),0LL);
        cnt += max(0LL,temp-(1<<i));
        if(cnt & 1){
            ans |= (1<<i);
		}
  }
    return ans;
}

int seg[100000];

void build(int v, int a[], int l, int r){
	if(l == r){
		seg[v] = a[l];
		return;
	}
	else{
		int mid = (l+r)/2;
		build(2*v,a,l,mid);
		build(2*v+1,a,mid+1,r);
		seg[v] = seg[2*v] + seg[2*v+1];
	}
}

void update(int v, int l, int r, int pos, int val){
	if(l == r){
		seg[v] = val;
		return;
	}
	int mid = (l+r)/2;
	if(pos <= mid){
		update(2*v,l,mid,pos,val);
	}
	else
		update(2*v+1,mid+1,r,pos,val);
	seg[v] = seg[2*v] + seg[2*v+1];
}

int getSum(int v, int l, int r, int tl, int tr){
	if(l > r)
		return 0;
	if(l == tl && r == tr){
		return seg[v];
	}
	int mid = (tl+tr)/2;
	return getSum(2*v,l,min(mid,r),tl,mid) + getSum(2*v+1,max(l,mid+1),r,mid+1,r);
}


vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = xorring(A[i]);
    }
    vector<int> ans;
    build(1,a,0,n-1);
    for(int i = 0; i < (int)B.size(); i++){
		if(B[i][0] == 1){
			update(1,0,n-1,B[i][1],B[i][2]);
			ans.push_back(-1);
		}
		else{
			ans.push_back(getSum(1,B[i][1],B[i][2],0,n-1));
		}
	}
	return ans;
}


int32_t main(){
	//int n = 17;
	//cout << xorring(n) << endl;
	
	//int ans = 0;
	//for(int i = 1; i <= n; i++)
		//ans ^= i;
		
	//cout << ans << endl;
	vector<int> a = {8,4,1,18,10,10,3,16,12,13,2,10};
	vector<vector<int>> b = {
							{1,6,20},
							{1,9,20},
							{2,1,7},
							{1,0,7},
							{1,6,19},
							{2,5,6}
	};
	vector<int> ans = solve(a,b);
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
	return 0;
}

