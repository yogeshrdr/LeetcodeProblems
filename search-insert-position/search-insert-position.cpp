class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid, pos=-1;
        
        while(r>=l){
            mid = l+(r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
            {
                l = mid+1;
                pos = mid+1;
            }
            else
            {
               pos =mid;
               r = mid-1;
            }     
        }
        
        return pos;
    }
};