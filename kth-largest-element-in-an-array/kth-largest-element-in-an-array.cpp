class Solution {
public:
    int partition(vector<int>&nums,int l,int r){
        
        int rnd = (rand() % (r - l + 1)) + l;
        swap(nums[rnd] , nums[r]);
        
        int idx = l;
        
        for(int i = l ; i < r ; i++){
           if(nums[i] < nums[r]){
            swap(nums[i] , nums[idx]);
            idx++;
           }
        }
        swap(nums[idx] , nums[r]);
        return idx;
    }
    
    int quickSelect(vector<int>&nums,int l,int r,int k){
        while(l <= r){
           int p= partition(nums,l,r);
           if(p == k)
             return nums[p];
           if(p < k)
               return quickSelect(nums, p+1, r, k);
           else
               return quickSelect(nums, l, p-1, k);
         }
         return -1;
    }
    
    int findKthLargest(vector<int>&nums, int k) {
        int n = nums.size();
        return quickSelect(nums,0,n-1,n-k);
    }
};