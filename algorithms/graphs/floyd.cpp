#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int > vi;
typedef pair<int, int> pi;
typedef vector<pi> vp;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD 1000000007
#define EPS 1e-9
#define REP(i,a,b) for(ll i=a;i<=b;i++)
#define n 7

int main(){
	
	int succ[n+1]={0,2,3,4,5,6,7,3};
	int x = 1;
	int a, b;

	a = succ[x];
	b = succ[succ[x]];
	while (a != b){
		a = succ[a];
		b = succ[succ[b]];
	}

	a = x;
	while(a != b){
		a = succ[a];
		b = succ[b];
	}
	int first = a;

	b = succ[a];
	int length=1;
	
	while(a != b){
		b = succ[b];
		length++;
	}

	cout << "Length of Cycle is "<< length <<"\n"; 

	return 0;
}
