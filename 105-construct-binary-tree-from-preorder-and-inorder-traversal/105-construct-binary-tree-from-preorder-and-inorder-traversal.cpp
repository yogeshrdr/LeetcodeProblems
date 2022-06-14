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
    
    TreeNode * solve(vector<int>&preorder, vector<int>&inorder, int index, int inStart, int inEnd, unordered_map<int,int>&mp){
        if(index >= preorder.size() || inStart > inEnd)
            return NULL;
        
        int x = preorder[index];
        TreeNode *root = new TreeNode(x);
        int pos = mp[x];
        
        root->left = solve(preorder, inorder, index+1, inStart, pos-1, mp);
        root->right = solve(preorder, inorder, index + pos - inStart + 1, pos+1, inEnd, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]] = i;
        
        
        return solve(preorder, inorder, 0, 0, inorder.size()-1, mp);
    }
};