class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int l = 0, r = nums.size()-1;
        
        if(nums[l]<nums[r])
            return nums[l];
        
        while(r>=l){
            
            while(r>l && nums[l]==nums[l+1])
                ++l;
            
            while(r>l && nums[r] ==nums[r-1])
                --r;
            
            if(l==r)
                return nums[l];
            
            int m = l+(r-l)/2;
            
            if(nums[m]>nums[m+1])
                return nums[m+1];
            
            if(nums[m-1]>nums[m])
                return nums[m];
            
            if(nums[m]>nums[l])
                l=m+1;
            else
                r=m-1;
                
        }
        return -1;
    }
};