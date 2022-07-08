class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0,ans = INT_MIN;
        
        for(auto i: nums){
            sum += i;
            ans = max(ans, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return ans;
        
    }
};