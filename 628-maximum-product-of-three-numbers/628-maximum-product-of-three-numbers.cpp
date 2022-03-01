class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size()-1;
        
        int product1 = nums[n] * nums[n-1] * nums[n-2];
        int product2 = nums[n] * nums[0] * nums[1];
        
        int maxProduct = max(product1, product2);
        
        return maxProduct;
    }
};