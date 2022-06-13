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
    bool getPath(TreeNode* root, vector<TreeNode *>&arr, TreeNode*x){
        if(root == NULL)
            return false;
        
        arr.push_back(root);
        
        if(root == x)
            return true;
        
        if(getPath(root->left, arr, x) || getPath(root->right, arr, x))
            return true;
        
        arr.pop_back();
        
        return false;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode *> arr;
        getPath(root, arr, p);
        
        vector<TreeNode *> x = arr;
        arr.clear();
        
        getPath(root, arr, q);
        
        reverse(x.begin(), x.end());
        reverse(arr.begin(), arr.end());
        
        for(int i=0;i<x.size();i++)
            for(int j=0;j<arr.size();j++)
                if(x[i]==arr[j])
                    return x[i];
        
        
        
        return root;
    }
};