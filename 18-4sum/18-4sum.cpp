class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        
        if(nums.size()<4) 
            return v;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size()-3;i++){
            
            for(int j=i+1;j<nums.size()-2;j++){
                
                int two_sumTarget = target - (nums[i]+nums[j]);
                int l=j+1;
                int m=nums.size()-1;
                
                while(l<m){
                    int sum=nums[l]+nums[m];
                    
                    if(sum>two_sumTarget) 
                        m--;
                    else if(sum<two_sumTarget) 
                        l++;
                    else{
                        v.push_back({nums[i], nums[j], nums[l], nums[m]});
                        
                        while(l<m-1 && nums[m]==nums[m-1]) 
                            m--;
                        while(l+1<m && nums[l]==nums[l+1]) 
                            l++;
                        l++;
                        m--;
                    }
                }
                
                while(j+1<nums.size() && nums[j+1]==nums[j]) 
                    j++;
            }
            
            while(i+1<nums.size() && nums[i+1]==nums[i]) 
                i++;
        }
        return v;
       
    }
};