class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int x = abs(nums[i]) - 1;
            
            if (nums[x] > 0)
                 nums[x] =-1 * nums[x] ;
            else 
                ans.push_back(abs(nums[i]));
        }
        
        return ans;
        
    }
};