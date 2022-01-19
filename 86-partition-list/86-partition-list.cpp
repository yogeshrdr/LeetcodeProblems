/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode *l1 = new ListNode(0);
         ListNode *l2 = new ListNode(0);
         
         
         ListNode *temp = head;
         ListNode *temp1 = l1;
         ListNode *temp2 = l2;
        
        while(temp!=NULL){
            if(temp->val<x){
                temp1->next = temp;
                temp1 = temp1->next;
            }

            else{
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        
        temp2->next = NULL;
        temp1->next = l2->next;
        return l1->next;
        
        
    }
};