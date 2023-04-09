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

void insertAtHead(node* &head, node* &tail, int val){
	if(head == NULL){
		head = new node(val);
		tail = head;
		return;
	}
	node* n = new node(val);
	n-> next = head;
	head = n;
}

void insertAtTail(node* &head, node* &tail, int val){
	if(tail == NULL){
		head = new node(val);
		tail = head;
		return;
	}
	node *n = new node(val);		// new node() return address of node created  in heap
	tail->next = n;
	tail = tail->next;
	return;
}

int length(node* head){
	int cnt = 0;
	while(head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insertInMiddle(node* &head, node* &tail, int pos, int val){
	int len = length(head);
	if(pos == 0){
		insertAtHead(head,tail,val);
	}
	else if(pos >= len){
		insertAtTail(head,tail,val);
	}
	else{
		node *cp = head;
		for(int i = 0; i < pos-1; i++){
			cp = cp->next;
		}
		node *temp = new node(val);
		temp->next = cp->next;
		cp->next = temp;
	}
}

void printAll(node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int search(node *head, int val){
	if(head == NULL){
		return -1;
	}
	if(head->data == val){
		return 0;
	}
	else{
		int x = search(head->next,val);
		if(x != -1){
			return x+1;
		}
		else
			return -1;
	}
}

node* reverse(node* head, node* &tail){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* newHead = reverse(head->next,tail);
	
	
	head->next->next = head;
	
	head->next = NULL;
	
	tail = head;		// To preserve tail
	
	return newHead;
}

void deleteInMiddle(node* &head, int pos){
	if(head == NULL)
		return;
	if(pos == 0){
		node* temp = head->next;
		head->next = NULL;
		delete head;
		head = temp;
		return;
	}
	if(pos >= length(head)){
		return;
	}
	node* temp = head;
	for(int i = 0; i < pos-1; i++){
		temp = temp->next;
	}
	node* p = temp->next->next;
	temp->next->next = NULL;
	delete temp->next;
	
	temp->next = p;
	
}

node* findmid(node* head){
	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* merge(node* a, node* b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	node* newHead;
	if(a->data <= b->data){
		newHead = a;
		newHead->next = merge(a->next,b);
	}
	else{
		newHead = b;
		newHead->next = merge(a,b->next);
	}
	return newHead;
}


node* mergeSort(node* head){
	if(head == NULL || head->next == NULL)
		return head;
	node* mid = findmid(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;
	
	a = mergeSort(a);
	b = mergeSort(b);
	return merge(a,b);
}


int32_t main(){
	node *head = NULL, *tail = NULL;
	
	insertAtTail(head,tail,15);
	insertAtTail(head,tail,6);
	insertAtTail(head,tail,71);
	insertAtHead(head,tail,37);
	insertAtTail(head,tail,11);
	
	printAll(head);
	
	insertInMiddle(head,tail,2,100);
	
	printAll(head);
	
	// Searching using recusive and iterative (skipping - easy)
	
	cout << search(head,17) << endl;
	
	// Reversing a linked list
	// Method 1 - Iterative
	tail = head;
	
	node* prev = NULL;
	node* cur = head;
	node* agla = head->next;
	
	while(cur != NULL){
		agla = cur->next;
		cur->next = prev;
		prev = cur;
		cur = agla;
	}
	head = prev;
	
	printAll(head);
	
	// Method 2 - Recursive
	head = reverse(head,tail);
	printAll(head);
	
	// Delete a given pos
	cout << "After Deleting ";
	deleteInMiddle(head,1);
	printAll(head);
	
	// Merge sort
	cout << "Sorted - ";
	head = mergeSort(head);
	printAll(head);

	return 0;
}

