class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int product = 1;
        int maxProduct = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            product = product * nums[i];
            maxProduct = max(maxProduct, product);
            
            if(product == 0){
                product = 1;
            }
        }
        
        
        product = 1;
        
        for(int i=nums.size()-1;i>=0;i--){
            product = product * nums[i];
            maxProduct = max(maxProduct, product);
            
            if(product == 0){
                product = 1;
            }
        }
        
        return maxProduct;
    }
};