class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i=0,j=0;
        
        unordered_map<char, int> mp;
        
        int maxlen = 0;
        
        while(j<s.size()){
            mp[s[j]]++;
            
            if(mp.size()<=2){
                maxlen = max(maxlen, j-i+1);
                j++;
            }else{
                while(mp.size()>2){
                    mp[s[i]]--;
                    
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]); 
                    i++;
                }
                j++;
            }
        }
        
        return maxlen;
    }
};