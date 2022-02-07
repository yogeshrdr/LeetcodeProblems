class Solution {
public:
  void solve(vector<int> nums, int i, vector<vector<int>>&ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        } 
      
        for(int j=i;j<nums.size();j++)
            if (j==i || nums[j]!=nums[i]){
                swap(nums[i], nums[j]);
                solve(nums, i + 1,ans);
            }
      
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>>ans;
        solve(nums, 0,ans);
        return ans;
    }
};