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

void bubble_sort(int a[], int i, int j, int n){
	if(i == n){
		return;
	}
	if(j == n-1){
		return bubble_sort(a,i+1,0,n);
	}
	else{
		if(a[j] > a[j+1])
			swap(a[j],a[j+1]);
		bubble_sort(a,i,j+1,n);
	}
}

void bubble_sort2(int a[], int i, int n){		// Bhaiya's approach
	if(n <= 1){
		return;
	}
	if(i == n-1){
		return bubble_sort2(a,0,n-1);
	}
	else{
		if(a[i] > a[i+1])
			swap(a[i],a[i+1]);
		bubble_sort2(a,i+1,n);
	}
}

int32_t main(){
	int a[] = {2,7,3,9,1,5,4,11,10};
	int n = sizeof(a)/sizeof(int);
	bubble_sort2(a,0,n);
	
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	
	return 0;
}

