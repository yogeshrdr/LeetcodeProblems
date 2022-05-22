class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int flag = 0;
        
        for(int i=0;i<nums.size();i++)
            if(nums[i] == 1)
                flag++;
        
        if(flag == 0)
            return 1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0 || nums[i] > nums.size())
                nums[i] = 1;
        }
        
        
        for(int i=0;i<nums.size();i++){
            int x = abs(nums[i]);
            
            if(x == nums.size())
                nums[0] = -1 * abs(nums[0]);
            else
                nums[x] = -1 * abs(nums[x]);
        }
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] > 0)
                return i;
        }
        
        return nums[0] > 0 ? nums.size() : nums.size()+1;
    }
};