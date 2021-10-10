class Solution {
public:
    int binarySearch(vector<int>&nums, int l, int r, int target){
        if(r>=l){
            int mid = l+(r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                return binarySearch(nums, l, mid-1, target);
            
            return binarySearch(nums, mid+1,r,target);
                
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        return binarySearch(nums, 0, size-1, target);
    }
};