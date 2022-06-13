/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        
        if(!root->left && !root->right)
            return NULL;
        
        TreeNode *left = NULL;
        TreeNode *right = NULL;
        
        if(root->left)
            left = lowestCommonAncestor(root->left, p, q);
        if(root->right)
            right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right)
            return root;
        
        return left == NULL ? right : left;
    }
};