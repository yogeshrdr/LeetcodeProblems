class Solution {
public:
    int solve(vector<int>&nums, vector<int>&memo, int i){
        if(i >= nums.size()-1) 
            return 0;
        
        if(memo[i]!=INT_MAX-1)
            return memo[i];
        
	    for(int j=1;j<=nums[i];j++)
		    memo[i] = min(memo[i], 1+solve(nums,memo,i+j));   
        
	    return memo[i];
    }
    
    int jump(vector<int>& nums) {
        
        vector<int>memo(nums.size(), INT_MAX-1);
        return solve(nums, memo, 0);
    }
};