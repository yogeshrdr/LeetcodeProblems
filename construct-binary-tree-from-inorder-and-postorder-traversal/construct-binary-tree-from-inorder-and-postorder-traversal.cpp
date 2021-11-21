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
    TreeNode* Tree(vector<int>& inorder,int inLow,int inHigh,vector<int>& postorder,int poLow,int poHigh)         {
        if (inLow>inHigh || poLow>poHigh) 
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[poHigh]);
        
        int inIndex = inLow;
            
        while(inorder[inIndex] != root->val) 
            inIndex++;
        
        int countLeftElement = inIndex-inLow;
        
        root->left = Tree(inorder, inLow, inIndex-1, postorder, poLow, poLow+countLeftElement-1);
        root->right = Tree(inorder, inIndex+1, inHigh, postorder, poLow+countLeftElement, poHigh-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         return Tree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};