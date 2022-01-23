class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        
        vector<int> ans(nums.size());

        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(s.size()!=0){
                while(s.size() >0 && s.top()<=nums[i])
                    s.pop();
                
                if(s.size()==0){
                    ans[i] = -1;
                    for(int j=0;j<i;j++)
                        if(nums[i] < nums[j]){
                            ans[i] = nums[j];
                            break;
                        }
                }
                    
                else
                    ans[i] = s.top();
            }
                 
            s.push(nums[i]);     
        }
       
        
        ans[nums.size()-1] = -1;
        
        int lastele = nums[nums.size()-1];
        
        for(int i=0;i<nums.size()-1;i++)
            if(lastele < nums[i]){
                ans[nums.size()-1] = nums[i];
                break;
            }
                
        return ans;
    }
};