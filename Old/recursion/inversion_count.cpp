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


int Merge(int a[], int s, int e){
	int temp[e-s+1];
	int mid = (s+e)/2;
	int l = s, r = mid+1;
	int t = 0, cnt = 0;
	while(l <= mid && r <= e){
		if(a[l] < a[r]){
			temp[t++] = a[l++];
		}
		else{
			cnt += (mid-l+1);
			temp[t++] = a[r++];
		}
	}
	while(l <= mid)
		temp[t++] = a[l++];
	while(r <= e)
		temp[t++] = a[r++];
	for(int i = s; i <= e; i++)
		a[i] = temp[i-s];
	return cnt;
}

int mergesort(int a[], int s, int e){
	if(s >= e)
		return 0;
	int ans = 0;
	
	int mid = (s + e)/2;
	ans += mergesort(a,s,mid);
	ans += mergesort(a,mid+1,e);
	ans += Merge(a,s,e);
	
	return ans;
}


int32_t main(){
	int a[] = {11,2,1,5,7,3,9};
	int n = sizeof(a)/sizeof(int);
	
	cout << mergesort(a,0,n-1);
	
	
	return 0;
}

