/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);
        
        while(!s1.empty()){
            TreeNode *temp = s1.top(); 
            s2.push(temp);
            s1.pop();
             
            if(temp->left != NULL)
                s1.push(temp->left); 
            
            if(temp->right != NULL)
                s1.push(temp->right); 
            
        }
        
        while(!s2.empty()){
            TreeNode* curr = s2.top();
            ans.push_back(curr->val);
            s2.pop();
        }
        
        return ans;
    }
};