// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
struct Node* deleteAllOccurances(struct Node *head,int );
void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}
/* Driver program to test above function*/

Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    while(head != NULL && head->data == x){
        head = head->next;
    }
    if(head == NULL)
        return head;
    Node *ans = head;
    while(head->next != NULL){
        while(head->next != NULL && head->next->data == x){
            Node *temp = head->next->next;
            head->next->next = NULL;
            delete head->next;
            head->next = temp;
        }
        if(head->next != NULL)
            head = head->next;
    }
    return ans;
}



int main()
{
  int T,i,n,l;
  // TO BE REMOVED
  //for (int i=0; i<2000; i++);
    cin>>T;
    //T = 10;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
	int kk;
	cin>>kk;
    head =deleteAllOccurances(head,kk);
    printList(head);
    }
    return 0;
}
