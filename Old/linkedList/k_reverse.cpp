#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    struct node* next;
    node(int x): data(x), next(NULL){}
};


node* rev(struct node* head){
    node* prev = NULL;
    node* cur = head;
    node *agla;
    while(cur != NULL){
        agla = cur->next;
        cur->next = prev;
        prev = cur;
        cur = agla;
    }
    head = prev;
    return head;
}


node *reverse (node *head, int k)
{ 
  if(head == NULL)
    return head;
  node *temp = head, *temp2 = head;
  int flag = 0;
  for(int i = 0; i < k; i++){
      temp = temp->next;
      if(temp == NULL){
        flag = 1;
        break;
      }
  }
  
  if(!flag){
      for(int i = 0; i < k-1; i++){
	      temp2 = temp2->next;
      }
      temp2->next = NULL;
  }
  struct node* tail = head;
  head = rev(head);
  tail->next = reverse(temp,k);
  return head;
}


void insertAtHead(node* &head, int val){
	if(head == NULL){
		head = new node(val);
		return;
	}
	node* n = new node(val);
	n-> next = head;
	head = n;
}


void printAll(node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



int main(){
	node* head = NULL;
	insertAtHead(head,9);
	insertAtHead(head,7);
	insertAtHead(head,5);
	insertAtHead(head,3);
	insertAtHead(head,1);
	
	printAll(head);
	
	head = reverse(head,3);
	
	printAll(head);
	
    
     return(0);
}
