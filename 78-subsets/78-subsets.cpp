class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int> temp,vector<int>& nums, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        vector<int> temp1 = temp;
        vector<int> temp2 = temp;
        temp2.push_back(nums[index]);
        
        solve(ans, temp1, nums, index+1);
        solve(ans, temp2, nums, index+1);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, nums, 0);
        
        return ans;
    }
};