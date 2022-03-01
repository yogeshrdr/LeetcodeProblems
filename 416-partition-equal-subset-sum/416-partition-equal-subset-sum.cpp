class Solution {
public:
    bool findSum(vector<int>&nums, int sum){
        int n = nums.size();
        bool t[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
            t[i][0] = true;
        
        for(int j=1;j<sum+1;j++)
            t[0][j] = false;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1] > j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] || t[i-1][j-nums[i-1]];
            }
        }
        
        return t[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int i=0;i<nums.size();i++)
            sum +=nums[i];
        
        if(sum%2!=0)
            return false;
        else
            return findSum(nums, sum/2);
    }
};