class Solution {
public:
    void solve(vector<string>&ans, unordered_map<char, string> mp, string digits, int index, string temp){
        
        if(index == digits.length()){
            ans.push_back(temp);
            return;
        }
        
        for(auto i: mp[digits[index]])
            solve(ans, mp, digits, index+1, temp+i);
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() <= 0)
            return ans;
        
        unordered_map<char, string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        int index = 0;
        
        solve(ans, mp, digits, 0, "");
        
        return ans;
    }
};