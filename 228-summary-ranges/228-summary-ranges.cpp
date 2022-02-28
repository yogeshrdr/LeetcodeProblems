class Solution {
public:
   
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int start = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(i+1 == nums.size() || nums[i]+1 != nums[i+1]){
                
                string x = to_string(nums[start]);
                if(i != start) 
                    x = x + "->"+to_string(nums[i]);
                
                ans.push_back(x);
                start = i+1;
            }
        }
        
        return ans;
    }
};