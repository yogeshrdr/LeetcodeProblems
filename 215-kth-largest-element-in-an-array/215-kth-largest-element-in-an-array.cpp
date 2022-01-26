class Solution {
public:
    int partition(vector<int>& nums , int l, int r) {
        int pivot = nums[r];
        int j = l;
        for (int i=l;i<=r;i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        swap(nums[j], nums[r]);
        return j;
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        if (k == 0 || nums.empty())
            return -1;
        
  
        int l = 0;
        int r = nums.size()-1;
        
        k= nums.size()-k;
        
        while(l < nums.size() && r >= 0) {
            int p = partition(nums, l, r);
            
            if (p == k) 
                return nums[p];
            else if (p > k) 
                r = p-1;
             else 
                l = p+1;
            
        }
        
        return -1;
    }
};