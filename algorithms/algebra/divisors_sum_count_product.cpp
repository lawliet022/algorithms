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


map<int,int> factors(int n){
	map<int,int> m;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0){
				m[i]++;
				n /= i;
			}
		}
	}
	if(n > 1)
		m[n]++;
	return m;
}


int countDivisors(map<int,int> m){
	int count = 1;
	for(auto x : m){
		count *= (x.S+1);
	}
	return count;
}


int sumDivisors(map<int,int> m){
	int sum = 1;
	for(auto x : m){
		sum *= (pow(x.F,x.S+1) - 1) / (x.F-1);
	}
	return sum;
}


int productDivisors(int n, int count){

	return pow(n,count/2);
}



int32_t main(){
	
	int n = 6;
	map<int, int> div = factors(n);

	int count = countDivisors(div);
	int sum = sumDivisors(div);

	cout << "Number of divisors = " << count << "\n";
	cout << "Sum of Divisors = " << sum << "\n";
	cout << "Product of Divisors = " << productDivisors(n, count) << "\n";
	


	return 0;
}
