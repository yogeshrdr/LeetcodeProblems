class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        unordered_map<char,int>m;
        int i=0, j=0;
        int ans = 0;
        
        while(j<s.size()){
            
            if(m[s[j]]==0){
                ans = max(ans, j-i+1);
                m[s[j]]++;
                j++;
            }
            else{
                m[s[i]]--;
                i++;
            }
        }
        
        return ans;
    }
};