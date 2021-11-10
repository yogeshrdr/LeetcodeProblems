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
    ListNode* merge (ListNode* l1,ListNode* l2) {
       ListNode dummy;
       ListNode* p = &dummy;
        
        while (l1 || l2) {
            if (l1 && (!l2 || l1->val < l2->val)) {
                p = p->next = l1;
                l1 = l1->next;
            }
            if (l2 && (!l1 || l1->val >= l2->val)) {
                p = p->next = l2;
                l2 = l2->next;
            }
        }
        p->next = NULL;
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast && fast->next){   
            fast= fast->next->next;
            slow = slow->next;
        }
        
        ListNode* headb = slow->next;
        slow->next = NULL; 
        return merge(sortList(head) , sortList(headb));
    }
};