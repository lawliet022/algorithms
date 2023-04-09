#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
using namespace std;

bool ok(int x){
	if(x < 10){
		return 0;
	}
	else
		return 1;
}

int ok2(int x){			// return max value = 15
	if(x == 15){
		return 15;
	}
	else if(x > 15){
		return 30 - x;
	}
    else
        return x;
}


int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(0);

    // Note: Must be sorted

    int a[] = {1, 3, 5, 5, 5, 7, 9, 13, 24};
    auto p = lower_bound(a, a+9, 5);        //returns the pointer to first ele whose value is atleast x
    auto q = upper_bound(a, a+9, 5);        //returns the pointer to first ele whose value is larger than x
    cout << q - p << "\n";
	
	// Or can also do
    auto pt = equal_range(a, a+9, 5);
    cout << pt.second - pt.first << "\n";

    
    // finding smallest index where function value changes
    int ans = -1;                       
    int l = 0, r = 100;
    while(l <= r){
		int mid = (l+r)/2;
		if(!ok(mid)){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
    cout << ans + 1 << "\n";

    
    
    // finding index of minima or maxima
	l = 0;	r = 100;
	ans = -1;
	while(l <= r){
		int mid = (l+r)/2;
		if(ok2(mid) < ok2(mid+1)){
			ans = mid;
			l = mid+1;
		}
		else
			r = mid-1;
	}
	cout << ans + 1 << endl;


	return 0;
}

