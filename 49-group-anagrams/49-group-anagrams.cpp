class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto s : strs) {
            string x = s; 
            sort(x.begin(), x.end());
            mp[x].push_back(s);
        }
        
        vector<vector<string>> ans;
        
        for (auto i : mp) { 
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
};