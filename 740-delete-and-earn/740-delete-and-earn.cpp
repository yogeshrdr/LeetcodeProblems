class Solution {
public:    
    
    int solve(vector<int>&nums, int i, vector<int>&memo){
        if(i>=nums.size())
            return 0;
        
        if(memo[i]!=-1)
            return memo[i];
        
        int sum = nums[i];
        int j = i+1;
        
        while(j<nums.size() && nums[j] == nums[i]){
            sum += nums[j];
            j++;
        }
        
        while(j<nums.size() && nums[j] == nums[i]+1)
            j++;
        
        memo[i] = max( sum + solve(nums, j, memo), solve(nums, i+1, memo));
        
        return memo[i];
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    
        
        vector<int> memo(20001, -1);
        
        return solve(nums, 0, memo);
    }
};