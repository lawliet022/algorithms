#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD 1000000007
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5;
const int INF = 1e9;
multiset<int> seg[4*MAX];

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		seg[v].insert(a[tl]);
	}
	else{
		int mid = (tl+tr)/2;
		build(a,2*v,tl,mid);
		build(a,2*v+1,mid+1,tr);

		for(auto x : seg[2*v])
			seg[v].insert(x);
		for(auto x : seg[2*v+1])
			seg[v].insert(x);
	}
}

int getElement(int v, int l, int r, int tl, int tr, int ele){
	if(l > r)
		return INF;
	if(tl == l && tr == r){
		auto p = seg[v].lower_bound(ele);
		if(p == seg[v].end())
			return INF;
		else
			return *p;
	}
	else{
		int mid = (tl+tr)/2;
		return min(getElement(2*v,l,min(r,mid),tl,mid,ele), getElement(2*v+1,max(mid+1,l),r,mid+1,tr,ele));
	}
}

void update(int a[],int v, int tl, int tr, int pos, int ele){
	seg[v].erase(seg[v].find(a[pos]));			// removing and add while going down the tree because at leaf, value of a[pos] will change
	seg[v].insert(ele);							// So better to use cur val of a[val] now only to find and erase value
	if(tl == tr){
		a[pos] = ele;
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update(a,2*v,tl,mid,pos,ele);
		else
			update(a,2*v+1,mid+1,tr,pos,ele);
	}
}


int32_t main(){
	int a[] = {5,1,9,3,7,4,11,105,64,32,-1,39};
	int n = sizeof(a)/sizeof(int);
	
	build(a,1,0,n-1);
	
	cout << getElement(1,7,n-1,0,n-1,2) << endl;
	
	update(a,1,0,n-1,n-1,3);
	
	cout << getElement(1,7,n-1,0,n-1,2) << endl;
	

	return 0;
}
