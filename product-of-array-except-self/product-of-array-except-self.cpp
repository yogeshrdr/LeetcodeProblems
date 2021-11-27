class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int countzero = 0;
        vector<int> v;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                product = product * nums[i];
            else
                countzero++;
                
        }
            
        for(int i=0;i<nums.size();i++){
            int x = 0;
            if(countzero == 0){
                x = product/nums[i];
            }
            else if(countzero == 1 && nums[i]==0){
                x = product;
            }
                v.push_back(x);
        }
        
        return v;
        
    }
};