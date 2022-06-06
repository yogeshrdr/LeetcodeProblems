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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        int len1 = 0, len2 =0;
        
        while(temp1!=NULL){
            len1++;
            temp1=temp1->next;
        }
        
        while(temp2!=NULL){
            len2++;
            temp2=temp2->next;
        }
        
        int count = abs(len1 - len2);

		if(len1 > len2){
			while(count){
				headA = headA -> next;
				count--;
			}
		}
		else{
			while(count){
				headB = headB -> next;
				count--;
			}
		}
        
        while(headA != NULL && headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
    }
};