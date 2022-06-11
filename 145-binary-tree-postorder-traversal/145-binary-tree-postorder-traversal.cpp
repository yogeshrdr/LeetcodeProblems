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
    void solve(TreeNode* root, vector<int>&ans){
        if(root == NULL)
            return;
        
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
       if(root==NULL)
           return {};
        
        vector<int> ans;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root);
        
        while(!s1.empty()){
            TreeNode *temp = s1.top();
            s2.push(temp);
            s1.pop();
            
            if(temp->left!=NULL)
                s1.push(temp->left);
            if(temp->right!=NULL)
                s1.push(temp->right);
        }
        
        
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};