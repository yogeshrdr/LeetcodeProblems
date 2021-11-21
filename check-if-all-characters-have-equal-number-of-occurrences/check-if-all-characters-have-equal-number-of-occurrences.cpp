class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        
        for(auto c:s)
            mp[c]++;
        
        int count = mp[s[0]];
        
        for(auto it:mp)
            if(it.second != count)
                return false;
        return true;
    }
};