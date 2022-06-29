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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        
        queue<TreeNode *> q;
        q.push(root);
        vector<int> temp;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                TreeNode *node = q.front();
                temp.push_back(node->val);
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};