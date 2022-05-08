class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        
        int min_ele = nums[0];
        int result = -1;
        
        for(int i=1;i<nums.size();i++){
            if(min_ele >= nums[i]){
                min_ele = nums[i];
            }else{
                result = max(nums[i] - min_ele, result);
            }
        }
              
        return result;
    }
};