// GFG problem

//Given n people standing in a circle where 1st is having sword, find the luckiest person in the circle, 
//if from 1st soldier who is having a sword each have to kill the next soldier and handover the sword to next soldier, 
//in turn, the soldier will kill the adjacent soldier and handover the sword to next soldier such that
//one soldier remains in this war who is not killed by anyone.


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


struct node{
    int n;
    node *next;
    node(int x): n(x), next(NULL){}
};

int32_t main(){
	ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        node *a = new node(1);
        node *start = a;
        for(int i = 2; i <= n; i++){
            node *temp = new node(i);
            a->next = temp;
            a = a->next;
        }
        a->next = start;
        while(start->next != start){
            node* temp = start->next->next;
            delete(start->next);
            start->next = temp;
            start = start->next;
        }
        cout << (start->n)  << endl;
            
    }
	// Note - This problem cannot be solved by array as n can be 1e8
	// Linked List is effective here

	return 0;
}
