class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r =nums.size()-1;
        
        while (l<r-1) {
            int m = l+(r-l)/2;
            
            if (nums[m] > nums[m-1] && nums[m] > nums[m+1]) 
                return m;
            
            else if (nums[m] > nums[m+1]) 
                    r = m-1;
                 else 
                    l = m+1;    
        }
        
        return nums[l] > nums[r] ? l : r;
    }
};