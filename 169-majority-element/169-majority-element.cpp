class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()<2)
            return nums[0];
        
        sort(nums.begin(), nums.end());
        
        int count=1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                count++;
                if(count>nums.size()/2)
                    return nums[i];
            }
            
            else
                count = 1;
        }
        
        return -1;
    }
};