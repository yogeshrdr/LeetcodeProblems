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
    vector<int> ans;
    
    void printleft(TreeNode* root){
        if(!root)
            return;
        
        if(!root->left&&!root->right)
            return;
        
        ans.push_back(root->val);
        
        if(!root->left)
            printleft(root->right);
        else
            printleft(root->left);
    }
    
    void printleaf(TreeNode* root){
        if(!root)
            return;
        printleaf(root->left);
        
        if(!root->left && !root->right)
            ans.push_back(root->val);
        
        printleaf(root->right);
    }
    
    
    void printright(TreeNode* root){
        if(!root)
            return;
        
        if(!root->left&&!root->right)
            return;
        
        if(!root->right)
            printright(root->left);
        else 
            printright(root->right);
        
        ans.push_back(root->val);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return ans;
        
        ans.push_back(root->val);
        
        printleft(root->left);
        printleaf(root->left);
        printleaf(root->right);
        printright(root->right);
        
        return ans;
    }
};