class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = -1, counter=0;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                if(counter==0){
                    v.push_back(i);
                    counter++;
                }
                x = i;
            }
        }
        
        v.push_back(x);
        
        if(counter == 0)
            v.push_back(-1);
        
        return v;
    }
};