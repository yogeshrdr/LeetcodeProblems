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
    
    void solve(TreeNode* root, int targetSum, vector<vector<int>>&ans, vector<int>temp){
        if(root==NULL)
            return;
        
        temp.push_back(root->val);
        
        if(root->val == targetSum && root->left==NULL && root->right == NULL)
            ans.push_back(temp);
        
        solve(root->left, targetSum-root->val, ans, temp);
        solve(root->right, targetSum-root->val, ans, temp);
            
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, ans, temp);
        return ans;
    }
};