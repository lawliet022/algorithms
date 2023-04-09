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


void solve(){
	int a[] = {1,4,5,6,7,2,5,9,12,10,13,7};
	int n = sizeof(a)/sizeof(int);
	int k = 5;
	deque<pair<int,int>> q;
	int added = 0, removed = 0; 
	for(int i = 0; i < k; i++){
		while(!q.empty() && q.back().F > a[i])
			q.pop_back();
		q.push_back({a[i],added});
		added++;
	}
	cout << "Min in array in all subarrays of length = " << k << " are\n";
	cout << q.front().F << " ";
	for(int i = k; i < n; i++){
		if(!q.empty() && q.front().S == removed)
			q.pop_front();
		removed++;
		while(!q.empty() && q.back().F > a[i])
			q.pop_back();
		q.push_back({a[i],added});
		added++;
		cout << q.front().F << " ";
	}
	cout << endl;
}



int32_t main(){
	int a[] = {5,7,4,6,3,9,2,10,1};
	int n = sizeof(a)/sizeof(int);
	
	// Stack
	stack<pair<int,int>> s;
	for(int i = 0; i < n; i++){
		// Adding an element
		int mini = s.empty() ? a[i] : min(a[i],s.top().S);
		s.push({a[i],mini});
	}
	
	// Removing top element
	s.pop();
	cout << "Min till here " << s.top().S << endl;

	
	
	// Queue - 1 Number are deleted in order they are inserted only (we need to know what number to delete)
	deque<int> q;
	for(int i = 0; i < n; i++){
		// Adding an element
		while(!q.empty() && q.back() > a[i])
			q.pop_back();
		q.push_back(a[i]);
	}
	
	// Removing an element
	int remove = 5;							// remember elements are removed only in order
	if(!q.empty() && q.front() == remove)
		q.pop_front();
	
	cout << "Min element now " << q.front() << "\n";
	
	// Queue - 2 Number are deleted in same order they are inserted (we need not know the number to delete i.e. using index only)
	deque<pair<int,int>> q2;
	int added = 0;
	int removed = 0;
	for(int i = 0; i < n; i++){
		// Adding an element
		while(!q2.empty() && q2.back().F > a[i])
			q2.pop_back();
		q2.push_back({a[i],added});
		added++;
	}
	
	// removing an element
	if(!q.empty() && q2.front().S == removed)
		q.pop_front();
	removed++;
	
	
	// Finding minimum in all subarrays of length k
	solve();



	return 0;
}
