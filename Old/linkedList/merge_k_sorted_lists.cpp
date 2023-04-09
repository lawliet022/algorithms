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

class node{
public:
	int data;
	node* next;
	node(int x): data(x), next(NULL){}
};

void insertAtTail(node* &head, node* &tail, int val){
	if(head == NULL){
		head = new node(val);
		tail = head;
		return;
	}
	node* temp = new node(val);
	tail->next = temp;
	tail = tail->next;
}

void printAll(node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node* merge(node* a, node* b){
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	node* newHead = NULL;
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

node* mergeKLists(node* a[], int k){
	int r = k-1;
	while(r){
		int t = 0;
		for(int i = 0; i <= r; i += 2){
			if(i+1 <= r)
				a[t++] = merge(a[i],a[i+1]);
			else
				a[t++] = a[i];
		}
		t--;
		r = t;
	}
	return a[0];
}

int32_t main(){
	int k;
	cin >> k;
	node *a[k+1], *b[k+1];
	for(int i = 0; i < k; i++){
		a[i] = b[i] = NULL;
		cout << "Enter number of elements in " << i+1 << " list - ";
		int x, p;
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> p;
			insertAtTail(a[i],b[i],p);
		}
	}
	node *head = mergeKLists(a,k);
	cout << "Sorted - ";
	printAll(head);

	return 0;
}

