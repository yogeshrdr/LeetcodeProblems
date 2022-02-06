class Solution {
public:
    void solve(vector<int>& nums, int target, int&count, int sum, int index){
        if(index == nums.size()){
            if(target == sum)
                count = count+1;
            return;
        }
        
        int sum1 = sum - nums[index];
        int sum2 = sum + nums[index];
        
        solve(nums, target, count, sum1, index+1);
        solve(nums, target, count, sum2, index+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(nums, target, count , 0, 0);
        return count;
    }
};