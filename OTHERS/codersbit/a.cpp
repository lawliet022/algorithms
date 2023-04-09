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

struct comp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};
string solve(vector<int> &A) {
    int n = A.size();
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        int temp = A[i];
        a[i] = 0;
        while(temp){
            a[i] += temp % 10;
            temp /= 10;
        }
    }
    for(int i = 0; i < n; i++){
        int temp = A[i];
        b[i] = 1;
        
        while(temp){
            b[i] *= (temp % 10);
            temp /= 10;
        }
    }
    map<int,priority_queue<pair<int,int>>,comp> sumi, prod;
    int ans1 = 0, ans2 = 0;
    
    for(int i = 0; i < n; i++){
        sumi[a[i]].push({A[i],i});
    }
    for(int i = 0; i < n; i++){
        prod[b[i]].push({A[i],i});
    }
    int done[n];
    for(int i = 0; i < n; i++)
        done[i] = 0;
    
    int cnt = 0;
    while(cnt < n){
        if(cnt % 2 == 0){   // Ram's turn
            pair<int,int> x;
            do{
                x = (*sumi.begin()).second.top();
                (*sumi.begin()).second.pop();
                if((*sumi.begin()).second.empty()){
                    sumi.erase(sumi.begin());
                }
            }
            while(done[x.second] == 1);
            done[x.second] = 1;
            ans1 += x.first;
        }
        else{                    // Shyam's turn
            pair<int,int> x;
            do{
                x = (*prod.begin()).second.top();
                    (*prod.begin()).second.pop();
                    if((*prod.begin()).second.empty()){
                        prod.erase(prod.begin());
                    }
                }
            while(done[x.second] == 1);
            done[x.second] = 1;
            ans2 += x.first;
        }
        cnt++;
    }
    if(ans1 > ans2)
        return "Ram";
    else if(ans1 < ans2)
        return "Shyam";
    else
        return "Draw";
}


int32_t main(){
	vector<int> a = {4,11,3,22,7};
	cout << solve(a);

	return 0;
}

