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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
     	unordered_map<int,int> m;
        
        ListNode *temp = head;

        while(temp!=NULL){
            m[temp->val]++;
            temp = temp->next;
        }
        
        ListNode * newList = new ListNode(0);
        ListNode *prev = newList;
        temp = head;
        
        while(temp!=NULL){

            if(m[temp->val] == 1){
		        ListNode *tempNext = temp->next;
                temp->next = NULL;

                prev->next = temp;
                prev = prev->next;

                temp = tempNext;
            }
            
            else{
                temp = temp->next;
            }
		
        }
        
        return newList->next;
    }
};