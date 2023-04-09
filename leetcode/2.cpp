/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* ans;
        int rem = (l1->val + l2->val)/10;
        head = new ListNode((l1->val + l2->val)%10);
        ans = head;
        l1 = l1 -> next;
        l2 = l2 -> next;
        while(l1 != NULL && l2 != NULL){
            head->next = new ListNode((l1->val + l2->val + rem)%10);
            rem = (l1->val + l2->val + rem)/10;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            head->next = new ListNode((l1->val + rem)%10);
            rem = (l1->val + rem)/10;
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            head->next = new ListNode((l2->val + rem)%10);
            rem = (l2->val + rem)/10;
            head = head->next;
            l2 = l2->next;
        }
        if(rem){
            head->next = new ListNode(rem);
        }
            
        return ans;
    }
};
