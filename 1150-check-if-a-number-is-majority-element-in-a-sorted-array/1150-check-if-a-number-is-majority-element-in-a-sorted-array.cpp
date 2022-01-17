class Solution {
public:
    int firstOccurence(vector<int>& nums, int target){
        int l=0, r=nums.size()-1;
        
        while(l<=r){
            int m = l+(r-l)/2;
            
            if(nums[m]<target)
                l = m+1;
            else
                r = m-1;
        }
        return l;
    }
    
    bool isMajorityElement(vector<int>& nums, int target) {
        int firstOccur = firstOccurence(nums, target);
        
        int lastOccur = firstOccur + nums.size()/2;
        
        if(lastOccur < nums.size())
            if(nums[lastOccur] == target)
                return true;
        
            
            return false;
    }
};