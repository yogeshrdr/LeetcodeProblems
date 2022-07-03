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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newlist = new ListNode(0);
        ListNode *temp = newlist;
        int carry = 0;
        
        while(l1||l2){
            int x = carry;
            
            if(l1!=NULL){
                x += l1->val;
                l1 = l1->next;
            }
            
            if(l2!=NULL){
                x += l2->val;
                l2 = l2->next;
            }
            
            carry = x/10;
            
            temp->next = new ListNode(x%10);
            temp = temp->next;
            
        }
        
        if(carry > 0){
            temp->next = new ListNode(carry);
            temp->next->next = NULL;
        }
        
        return newlist->next;
    }
};