class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        
        for (int i=0;i<nums.size() && nums[i]<=0; ++i)
            
            if (i==0 || nums[i-1]!=nums[i]){
                
            int j=i+1, k=nums.size()-1;
                
            while(j<k){
               int sum = nums[i] + nums[j] + nums[k];
                
               if (sum < 0) 
                   j++;
                
               else if (sum > 0) 
                   k--;
    
               else {
                ans.push_back({ nums[i], nums[j++], nums[k--] });
                while (j<k && nums[j] == nums[j-1])
                    j++;
               }
             }
        }
        return ans;
    }
};