#include<bits/stdc++.h>
using namespace std;


struct comparator{
	bool operator()(int a, int b){
		return a > b;
	}
};


int main(){
	// Set
	set<int,comparator> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	
	
	for(auto x : s)
		cout << x << " ";
	cout << endl;

	// Priority Queue
	priority_queue<int,vector<int>,comparator> q;
	q.push(5);
	q.push(6);
	q.push(7);
	
	while(!q.empty()){
		cout << q.top() <<  " ";
		q.pop();
	}
	
	cout << endl;
	
	// Map
	map<int,int,comparator> m;
	m[2] = 3;
	m[3] = 5;
	m[4] = 7;
	for(auto x : m){
		cout << x.first << " " << x.second << endl;
	}
	
	return 0;
}

