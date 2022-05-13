class Solution {
public:
    int pivotIndex(vector<int>& nums) {
               int sum=0;
        
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        int leftsum=0, rightsum=sum;
        
        for(int i=0;i<nums.size();i++){
            rightsum=rightsum-nums[i];
            
            if(leftsum==rightsum)
                return i;
            
            leftsum+=nums[i];
        }
        
        return -1; 
    }
};