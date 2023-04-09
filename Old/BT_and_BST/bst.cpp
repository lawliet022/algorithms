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
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}
};


void insertIntoBST(node* &root, int val){
	if(root == NULL){
		node *n = new node(val);
		root = n;
		return;
	}
	if(val < root->data){
		insertIntoBST(root->left, val);
	}
	else
		insertIntoBST(root->right,val);
}


node* buildBST(){
	int x;
	cin >> x;
	node* root = NULL;
	
	while(x != -1){
		insertIntoBST(root,x);
		cin >> x;
	}
	return root;
}
void printAllLevelOptimised(node* root){
	if(root == NULL)
		return;
	queue<node *> q;
	q.push(root);
	while(!q.empty()){
		int cnt = q.size();
		while(cnt){
			node *temp = q.front();
			cout << temp->data << " ";
			if(temp->left != NULL)
				q.push(temp->left);
			if(temp->right != NULL)
				q.push(temp->right);
			q.pop();
			cnt--;
		}
		cout << endl;
	}
}


int search(node* root, int val){
	if(root == NULL)
		return false;
	if(root->data == val)
		return true;
	if(val < root->data)
		return search(root->left,val);
	else
		return search(root->right,val);
}

node* deleteNode(node* root, int val){
	if(root == NULL)
		return NULL;
	if(root->data == val){
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		else if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->left != NULL && root->right != NULL){
			node* temp = root->right;
			while(temp->left != NULL){
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = deleteNode(root->right,root->data);
			return root;
		}
	}
	else if(val < root->data){
		root->left = deleteNode(root->left,val);
		return root;
	}
	else{
		root->right = deleteNode(root->right,val);
		return root;
	}
}

node* array2BST(int a[], int l, int r){
	if(l > r)
		return NULL;
	int mid = (l+r)/2;
	node *n = new node(a[mid]);
	n->left = array2BST(a,l,mid-1);
	n->right = array2BST(a,mid+1,r);
	
	return n;
}

class Mypair{
public:
	node* head;
	node* tail;
};

Mypair tree2LL(node* root){
	Mypair p;
	if(root == NULL){
		p.head = p.tail = NULL;
		return p;
	}
	if(root->left == NULL && root->right == NULL){
		p.head = p.tail = root;
		return p;
	}
	if(root->left != NULL && root->right == NULL){
		Mypair q = tree2LL(root->left);
		q.tail->right = root;
		p.head = q.head;
		p.tail = root;
	}
	else if(root->left == NULL && root->right != NULL){
		Mypair q = tree2LL(root->right);
		p.head = root;
		p.head->right = q.head;
		p.tail = q.tail;
		return p;
	}
	else{
		Mypair q = tree2LL(root->left);
		Mypair r = tree2LL(root->right);
		q.tail->right = root;
		p.head = q.head;
		p.tail = r.tail;
		return p;
	}
}



int32_t main(){
	
	// Build BST
	node* root = buildBST();
	
	printAllLevelOptimised(root);
	
	// Search in BST	- worst case O(n)
	cout << search(root,5) << endl;
	
	// Delete a node
	root = deleteNode(root,10);
	
	cout << "After Deleting\n";
	printAllLevelOptimised(root);
	
	// Creating height balanced BST
	int a[] = {1, 3, 4, 7, 8, 9, 11, 13, 17};
	int n = sizeof(a)/sizeof(int);
	
	node* root2 = array2BST(a,0,n-1);
	
	cout << "Height Balanced BST\n"; 
	printAllLevelOptimised(root2);
	
	Mypair p = tree2LL(root);
	node* LL = p.head;
	while(LL != NULL){
		cout << LL->data << " -> ";
		LL = LL -> right;
	}

	return 0;
}

