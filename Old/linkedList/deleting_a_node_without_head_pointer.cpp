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


class node{

public:
	int data;
	node* next;
	node(int a): data(a), next(NULL){}
};



void insertAtHead(node* &head, int val){
	if(head == NULL){
		head = new node(val);
		return;
	}
	node* n = new node(val);
	n-> next = head;
	head = n;
}


void printAll(node *head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
}



int32_t main(){
	node *head = NULL;
	
	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);
	
	// Deleting last node
	
	//delete(head->next->next->next);	// Not a good idea because its previous node still has its address (!= NULL) and should give seg fault on OJs
	
	delete(head->next->next->next);
	head->next->next->next = NULL;		// Updating deleted address to NULL
	
	printAll(head);
	
	return 0;
}

