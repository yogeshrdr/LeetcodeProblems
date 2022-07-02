class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int> nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            if(i==idx || nums[i]!=nums[idx]){
                swap(nums[idx], nums[i]);
                solve(ans, nums, idx+1);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};