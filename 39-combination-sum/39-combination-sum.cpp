class Solution {
public:
    void findCombinations(vector<vector<int>>&ans, vector<int> temp, vector<int> candidates, int target, int i)     {
        
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[i] <= target){
            temp.push_back(candidates[i]);
            findCombinations(ans, temp, candidates, target - candidates[i] , i);
            temp.pop_back();
        }
        
        findCombinations(ans, temp, candidates, target, i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombinations(ans, temp, candidates, target, 0);
        
        return ans;
    }
};