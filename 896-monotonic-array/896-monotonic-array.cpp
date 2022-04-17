class Solution {
public:
    bool isinc(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]>nums[i+1])
                return false;
        return true;
    }
    
    bool isdec(vector<int>&nums){
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]<nums[i+1])
                return false;
        return true;
    }
    
    
    bool isMonotonic(vector<int>& nums) {
        return isinc(nums) || isdec(nums);
    }
};