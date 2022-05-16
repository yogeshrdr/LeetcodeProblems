class Solution {
public:
//     int solve(vector<int>&nums, vector<int>&memo, int i){
//         if(i >= nums.size()-1) 
//             return 0;
        
//         if(memo[i]!=INT_MAX-1)
//             return memo[i];
        
// 	    for(int j=1;j<=nums[i];j++)
// 		    memo[i] = min(memo[i], 1+solve(nums,memo,i+j));   
        
// 	    return memo[i];
//     }
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>dp(n, INT_MAX-1);    
        dp[n-1] = 0;
        
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if(i+j<n)
                    dp[i] = min(dp[i], 1+dp[i+j]);
            }
        }
        
        return dp[0];
    }
};