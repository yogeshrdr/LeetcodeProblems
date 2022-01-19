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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == NULL) 
            return NULL;
        
        if(head->next == NULL) 
            return head;
        
        ListNode *tempNode = new ListNode(0,head);
        
        ListNode * prev = tempNode;
        ListNode * curr = head;
        
        while(curr){
            if(curr->next != NULL && curr->next->val == curr->val){
                
                while(curr->next!=NULL && curr->next->val == curr->val)
                   curr = curr->next;
                
                curr = curr->next;
                prev->next = curr;
            }else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        return tempNode->next;
    }
};