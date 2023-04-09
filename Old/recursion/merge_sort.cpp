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


// Space complexity - O(n) for that extra array used


// Insertion Sort - For every element in the array move it towards start in sorted array at its justified position
// Selection Sort - Find min in the remaning array and swap it with the correct position
// Both selection and Insertion Works in O(n^2) with O(1) extra space


void Merge(int a[], int s, int e){
	int temp[e-s+1];
	int mid = (s+e)/2;
	int l = s, r = mid+1;
	int t = 0;
	while(l <= mid && r <= e){
		if(a[l] < a[r]){
			temp[t++] = a[l++];
		}
		else{
			temp[t++] = a[r++];
		}
	}
	while(l <= mid)
		temp[t++] = a[l++];
	while(r <= e)
		temp[t++] = a[r++];
	for(int i = s; i <= e; i++)
		a[i] = temp[i-s];
}

void mergesort(int a[], int s, int e){
	if(s >= e)
		return;
	int mid = (s + e)/2;
	mergesort(a,s,mid);
	mergesort(a,mid+1,e);
	Merge(a,s,e);
}


int32_t main(){
	int a[] = {2,1,5,7,3,9,11,13,54,23,45};
	int n = sizeof(a)/sizeof(int);
	
	mergesort(a,0,n-1);
	
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	return 0;
}

