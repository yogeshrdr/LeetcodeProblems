class Solution {
public:
    
    void solve(vector<int> nums, vector<int>temp,vector<vector<int>>&ans, int index ){
        
        ans.push_back(temp);
           
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i] == nums[i-1]) 
                continue;
            
            temp.push_back(nums[i]);
            solve(nums, temp, ans, i+1); 
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        
        if(nums.size() <= 0)
            return ans;
        
        vector<int> temp;
        
        solve(nums, temp, ans, 0);
        
        return ans;
    }
};