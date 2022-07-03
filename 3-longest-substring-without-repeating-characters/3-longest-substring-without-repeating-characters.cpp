class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        
        int i=0, j=0;
        
        int maxlen = 0;
        
        while(j<s.length()){
            if(mp[s[j]] == 0){
                maxlen = max(maxlen, j-i+1);
                mp[s[j]]++;
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
            }
        }
        
        return maxlen;
    }
};