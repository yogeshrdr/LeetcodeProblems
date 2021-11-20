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
    map<int, map<int, vector<int>>>mp;
    void dfs(TreeNode* root, int i, int j){
        if(!root)
            return;
        mp[i][j].push_back(root->val);
        dfs(root->left, i-1, j+1);
        dfs(root->right, i+1, j+1);
    }
    
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>v;
        
        if (!root) 
            return v;
        
        dfs(root, 0, 0);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            
            auto m = it->second;
            vector<int>temp;
            
            for (auto t = m.begin(); t != m.end(); t++) {
                vector<int>temp1 = t->second;
                for (auto i = 0; i < temp1.size(); i++)
                    temp.push_back(temp1[i]);
            }
            
            v.push_back(temp);
        }   
        return v;
        
    }
};