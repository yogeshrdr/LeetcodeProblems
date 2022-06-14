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
    TreeNode *badNode; 
    
    vector<TreeNode *> rootToNodePath(TreeNode *root, TreeNode *target){
        vector<TreeNode *> ans;
        
        if(!root)
            return ans;
        
        if(root == target){
            ans.push_back(root);
            return ans;
        }
        
        vector<TreeNode *> leftPath = rootToNodePath(root->left, target);
        
        if(leftPath.size() > 0){
            leftPath.push_back(root);
            return leftPath;
        }
        
        vector<TreeNode *> rightPath = rootToNodePath(root->right, target);
        
        if(rightPath.size() > 0){
            rightPath.push_back(root);
            return rightPath;
        }
        
        return ans;
    }
    
    void kNodesDown(TreeNode *root, int i, int k, vector<int> &ans){
	    if(!root || root == badNode) 
            return;

	    if(i == k){
		    ans.push_back(root->val);
	    }

	    kNodesDown(root->left, i+1, k, ans);
	    kNodesDown(root->right, i+1, k, ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path = rootToNodePath(root, target);
        
        vector<int> ans;
        
        for(int i=0;i<path.size();i++){
            if(i==0)
                badNode = NULL;
            else
                badNode = path[i-1];
            
            kNodesDown(path[i], 0, k, ans);
		    k--;
        }
        
        return ans;
    }
};