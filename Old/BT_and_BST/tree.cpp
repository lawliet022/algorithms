#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-9
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;



/*
        1		- Level 0
       / \
      2   3		- Level 1
     / \
    4   5		- Level 2
	
	Height of this tree is 3
*/






class node{
public:
	int data;
	node *left, *right;
	node(int x): data(x), left(NULL), right(NULL){}
};

node* buildTree(){
	int val;
	cin >> val;
	if(val == -1)
		return NULL;
	node *n = new node(val);
	n->left = buildTree();
	n->right = buildTree();
	return n;
}

void printPreorder(node *root){
	if(root == NULL)
		return;
	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}


void printInorder(node *root){
	if(root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}

void printPostorder(node *root){
	if(root == NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

int height(node *root){
	if(root == NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

void printAtLevelK(node *root, int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout << root->data << " ";
		return;
	}
	printAtLevelK(root->left,k-1);
	printAtLevelK(root->right,k-1);
}



void printAllLevel(node* root){
	int k = height(root);
	for(int i = 0; i < k; i++){
		printAtLevelK(root,i);
		cout << endl;
	}
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

int countNodes(node* root){
	if(root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int replaceValue(node* root){
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	int temp = root->data;
	root->data = replaceValue(root->left) + replaceValue(root->right);
	return temp+root->data;
}



node* buildLevelOrder(){
	queue<node*> q;
	int x;
	cin >> x;
	node* temp = new node(x);
	q.push(temp);
	while(!q.empty()){
		node* p = q.front();
		q.pop();
		int a, b;
		cin >> a >> b;
		if(a != -1){
			node* w = new node(a);
			p->left = w;
			q.push(w);
		}
		if(b != -1){
			node* w = new node(b);
			p->right = w;
			q.push(w);
		}
	}
	return temp;
}


int diameter(node* root){
	if(root == NULL)
		return 0;
	int a = height(root->left) + height(root->right);		// Diameter passing through current root node
	int b = max(diameter(root->left),diameter(root->right));
	return max(a,b);
}

class Mypair{
public:
	int height, diameter;
};

Mypair diameterOptimised(node *root){
	Mypair p;
	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}
	Mypair l = diameterOptimised(root->left);
	Mypair r = diameterOptimised(root->right);
	p.height = max(l.height,r.height) + 1;
	p.diameter = max(max(l.diameter,r.diameter),l.height+r.height);
	
	return p;
}

class HBPair{
public:
	int height;
	bool balanced;
};

HBPair isHeightBalanced(node* root){
	HBPair p;
	if(root == NULL){
		p.height = 0;
		p.balanced = true;
		return p;
	}
	HBPair l = isHeightBalanced(root->left);
	HBPair r = isHeightBalanced(root->right);
	
	if(abs(l.height-r.height) <= 1 && l.balanced && r.balanced){
		p.balanced = true;
	}
	else{
		p.balanced = false;
	}
	p.height = max(l.height,r.height) + 1;
	return p;
}

class PairIE{
public:
	int inc;
	int exc;
};

PairIE maxSum(node *root){
	PairIE p;
	if(root == NULL){
		p.inc = p.exc = 0;
		return p;
	}
	PairIE l = maxSum(root->left);
	PairIE r = maxSum(root->right);
	
	p.inc = root->data + l.exc + r.exc;
	p.exc = max(l.inc,l.exc) + max(r.inc, r.exc);
	
	return p;
}


void root2Leaf(node *root, vector<int>& v){
	if(root == NULL){
		return;
	}
	if(root->left == NULL && root->right == NULL){
		v.PB(root->data);
		for(auto x : v){
			cout << x << " => ";
		}
		cout << endl;
		v.pop_back();
		return ;
	}
	v.PB(root->data);
	root2Leaf(root->left,v);
	root2Leaf(root->right,v);
	v.pop_back();
}


void mirror(node *root){
	if(root == NULL)
		return;
	swap(root->left,root->right);
	mirror(root->left);
	mirror(root->right);
}

int32_t main(){
	node *root = NULL;
	root = buildTree();
	
	// Input 1 2 4 -1 -1 5 -1 -1 3 -1 -1
	
	cout << "Preorder -> ";
	printPreorder(root);
	cout << endl;
	
	cout << "Inorder -> ";
	printInorder(root);
	cout << endl;
	
	cout << "Postorder -> ";
	printPostorder(root);
	cout << endl;
	
	cout << "At level 2 => ";
	printAtLevelK(root,2);		// if only that level < height or else that level do not exist and it prints nothing
	
	cout << "Print levelwise:-\n";
	printAllLevel(root);				// Complexity - O(n^2)
	
	cout << "Also " << endl;
	printAllLevelOptimised(root);		// O(n)
	
	// Count Nodes
	cout << "Number of nodes = " << countNodes(root) << endl;
	
	// Replace value of every node by sum of its descendents
	replaceValue(root);
	
	printAllLevelOptimised(root);
	
	
	// Level Order build of a tree
	node* root2 = buildLevelOrder();
	
	// Input - 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1

	printAllLevelOptimised(root2);
	
	
	// Diameter of a tree
	cout << diameter(root2) << endl;		// O(n^2)
	
	cout << diameterOptimised(root2).diameter << endl;		// O(n)
	
	cout << isHeightBalanced(root2).balanced << endl;		// Input for not height balanced - 1 2 3 4 5 -1 -1 6 -1 -1 -1 -1 -1
	
	// Max sum without picking adjacent nodes
	PairIE p = maxSum(root2);
	cout << "max sum = " << max(p.inc,p.exc) << endl;
	
	
	// Print path from root->leaf
	vi v;
	root2Leaf(root,v);
	
	
	// Mirror of a tree (To change the pointers not just print)
	mirror(root2);
	printAllLevelOptimised(root2);
	
	return 0;
}
