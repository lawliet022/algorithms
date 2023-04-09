#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};
//Position this line where user code will be pasted.
void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}
void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}
// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}



//---------------------------------------Merge Sort-----------------------------------------------------


Node* findMid(Node* head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* a, Node* b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    Node *newHead;
    if(a->data <= b->data){
        newHead = a;
        Node* aageKa = merge(a->next,b);
        newHead->next = aageKa;
        aageKa->prev = newHead;
        
    }
    else{
        newHead = b;
        Node* aageKa = merge(a,b->next);
        newHead->next = aageKa;
        aageKa->prev = newHead;
    }
    newHead->prev = NULL;
    return newHead;
}

// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(head == NULL || head->next == NULL)
	    return head;
	Node *mid = findMid(head);
	Node *a = head;
	Node *b = mid->next;
	mid->next->prev = NULL;
	mid->next = NULL;
	
	a = sortDoubly(a);
	b = sortDoubly(b);
	
	return merge(a,b);
	
	
}

//------------------------------------------------------------------------------------------







// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}


