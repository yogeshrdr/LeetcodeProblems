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
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return lh>rh ? lh+1 : rh+1;
    }
    
    
    void solve(TreeNode* root, int h, int l , vector<vector<int>>&ans){
        if(root == NULL){
            return;
        }
        if(l == 1){
            ans[h].push_back(root->val);
        }
        if(l > 1){
            solve(root->left, h, l-1, ans);
            solve(root->right, h, l-1, ans);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        int h = height(root);
        
        vector<vector<int>> ans(h);
        
        if(root == NULL)
            return ans;
        
        for(int i=0;i<h;i++)
            solve(root, i, i+1, ans);
        
        return ans;
    }
};