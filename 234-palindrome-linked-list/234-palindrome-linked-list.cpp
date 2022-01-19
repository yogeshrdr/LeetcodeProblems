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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        
        ListNode newHead(0);
        ListNode *next = NULL, *p=fast;
        
        while(p){
            next = p->next;
            p->next = newHead.next;
            newHead.next = p;
            p = next;
        }
        
        fast = newHead.next;
        
        
        while(fast) {
            if(fast->val != head->val) 
                return false;
            fast = fast->next;
            head = head->next;
        }
        
        return fast == NULL;
        
    }
};