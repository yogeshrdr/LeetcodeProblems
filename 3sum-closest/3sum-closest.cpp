class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int diff = INT_MAX ;
        int n = nums.size() ;
        
        for(int i =0;i<n;i++){
            int j=i+1, k=n-1;
            while(j<k){
                int temp = nums[i] + nums[j] + nums[k];
                
                if(abs(target - temp) <= diff)
                {
                   ans = temp;
                   diff = abs(target - temp);
                }
                if(temp == target) 
                    return temp;
                else if(temp > target) 
                    k--;
                else 
                    j++;
            }
        }
        
      return ans;
    }
};