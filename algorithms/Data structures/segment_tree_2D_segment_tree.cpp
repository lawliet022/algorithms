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

// Can be used to find min,max,sum,etc of a subarray
const int MAX = 1000;

int seg[4*MAX][4*MAX];

int a[5][5] = {1,2,5,3,4,
				3,2,1,4,5,
				1,2,3,4,5,
				4,5,1,2,3,
				5,2,3,4,1};

int n = 5, m = 5;

void buildy(int vx, int lx, int rx, int vy, int ly, int ry){
	if(ly == ry){
		if(lx == rx)
			seg[vx][vy] = a[lx][ly];
		else
			seg[vx][vy] = seg[2*vx][vy] + seg[2*vx+1][vy];
	}
	else{
		int mid = (ly+ry)/2;
		buildy(vx,lx,rx,2*vy,ly,mid);
		buildy(vx,lx,rx,2*vy+1,mid+1,ry);
		seg[vx][vy] = seg[vx][2*vy] + seg[vx][2*vy+1];
	}
}


void buildx(int vx, int lx, int rx){
	if(lx != rx){
		int mid = (lx+rx)/2;
		buildx(2*vx,lx,mid);
		buildx(2*vx+1,mid+1,rx);
	}
	buildy(vx,lx,rx,1,0,m-1);
}


int sumy(int vx, int vy, int tly, int try_, int ly, int ry){
	if(ly > ry)
		return 0;
	if(tly == ly && try_ == ry){
		return seg[vx][vy];
	}
	else{
		int mid = (tly+try_)/2;
		return sumy(vx,2*vy,tly,mid,ly,min(mid,ry)) + sumy(vx,2*vy+1,mid+1,try_,max(mid+1,ly),ry);
	}
}



int sumx(int vx, int tlx, int trx, int lx, int rx, int ly, int ry){
	if(lx > rx)
		return 0;
	if(tlx == lx && trx == rx)
		return sumy(vx,1,0,m-1,ly,ry);
	else{
		int mid = (tlx+trx)/2;
		return sumx(2*vx,tlx,mid,lx,min(mid,rx),ly,ry) + sumx(2*vx+1,mid+1,trx,max(mid+1,lx),rx,ly,ry);
	}
}


void updatey(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int val){
	if(ly == ry){
		if(lx == rx)
			seg[vx][vy] = val;
		else
			seg[vx][vy] = seg[2*vx][vy] + seg[2*vx+1][vy];
	}
	else{
		int mid = (ly+ry)/2;
		updatey(vx,lx,rx,2*vy,ly,mid,x,y,val);
		updatey(vx,lx,rx,2*vy+1,mid+1,ry,x,y,val);
		seg[vx][vy] = seg[vx][2*vy] + seg[vx][2*vy+1];
	}
}


void updatex(int vx, int lx, int rx, int x, int y, int val){
	if(lx != rx){
		int mid = (lx+rx)/2;
		if(x <= mid)
			updatex(2*vx,lx,mid,x,y,val);
		else
			updatex(2*vx+1,mid+1,rx,x,y,val);
	}
	updatey(vx,lx,rx,1,0,m-1,x,y,val);
}



int32_t main(){
	buildx(1,0,n-1);
	cout << sumx(1,0,n-1,1,2,3,3) << endl;		// (1,3) to (2,3) 
	updatex(1,0,n-1,2,3,6);
	cout << sumx(1,0,n-1,1,2,3,3) << endl;		// (1,3) to (2,3) 
	
	return 0;
}
