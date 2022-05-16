class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(auto i: nums){
            mp[i]++;
            if(mp[i] == 2)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};