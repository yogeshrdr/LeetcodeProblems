/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* clone = head;
        unordered_map<Node*, Node*> map;
        
        while(clone) {
            Node* curr = new Node(clone->val);
            map[clone] = curr;
            
            clone = clone->next;
        }
        
        Node* res = new Node(-1);
        auto ret = head;
        
        
        while(head) {
            res = map[head];
            
            res->random = map[head->random];
            res->next = map[head->next];
            
            res = res->next;
            head = head->next;
        }
        
        
        return map[ret];
    }
};