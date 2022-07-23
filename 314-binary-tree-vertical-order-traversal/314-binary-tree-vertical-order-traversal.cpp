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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int , vector<int>> mp;
        
        if(root == NULL)
            return {};
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            TreeNode* a = x.first;
            int b = x.second;
            
            mp[b].push_back(a->val);
            
            if(a->left){
                q.push({a->left, b-1});
            }
            
            if(a->right){
                q.push({a->right, b+1});
            }
        }
        
        
        vector<vector<int>> ans;
        
        for(auto i: mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};