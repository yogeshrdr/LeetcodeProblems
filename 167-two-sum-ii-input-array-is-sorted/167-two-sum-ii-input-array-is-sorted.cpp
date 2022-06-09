class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        
        int i=0, j=numbers.size()-1;
        
        while(i<j){
            int sum = numbers[i] + numbers[j];
                
            if(sum == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            else if(sum < target)
                i++;
            else
                j--;
        }
        
        return ans;
    }
};