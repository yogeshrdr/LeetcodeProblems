class Solution {
public:
    
    void solve(string digits, vector<string>&ans, unordered_map<char, string>&mp, int i, string temp){
        if(i==digits.length()){
            ans.push_back(temp);
            return;
        }
        
        string x = mp[digits[i]];
        
        for(auto j:x){
            solve(digits, ans, mp, i+1, temp+j);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        
        vector<string> ans;
        
        unordered_map<char, string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        solve(digits, ans, mp, 0, "");
        
        return ans;
    }
};