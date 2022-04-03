class Solution {
public:
    
    int findFirst(vector<int>&nums, int target){
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            
            if((m==0 || nums[m-1] < target) && nums[m] == target)
                return m;
            else if(target > nums[m])
                l = m+1;
            else
                r = m-1;
        }
        
        return -1;
    }
    
    int findLast(vector<int>&nums, int target){
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            
            if((m == nums.size()-1 || nums[m+1] > target) && nums[m] == target)
                return m;
            else if(target >= nums[m])
                l = m+1;
            else
                r = m-1;
        }
        
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        
        return {first, last};
    
    }
};