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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        
        TreeNode * curr = root;
        
        while(curr!=NULL){
            if(curr->right == NULL){
                postorder.push_back(curr->val);
                curr = curr->left;
            }
            
            else{
                TreeNode *temp = curr->right;
                
                while(temp->left!=NULL && temp->left!=curr)
                    temp = temp->left;
                
                if(temp->left == NULL){
                    postorder.push_back(curr->val);
                    temp->left = curr;
                    curr = curr->right;
                }
                else{
                    temp->left = NULL;
                    curr = curr->left;
                }
            }
        }
        
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};