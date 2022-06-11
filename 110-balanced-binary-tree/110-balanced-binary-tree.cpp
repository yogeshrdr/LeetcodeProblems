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
    int solve(TreeNode  * root){
        if(root == NULL)
            return 0;
        
        int x = solve(root->left);  
        int y = solve(root->right);
        
        if(abs(x-y) > 1 || x==-1 || y==-1)
            return -1;
        
        return 1+max(x,y);
        
    }
    bool isBalanced(TreeNode* root) {
        if(solve(root) == -1)
            return false;
        return true;
    }
};