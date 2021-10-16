class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int ans = 0;
 
    for (int i=0;i<n;i++) 
    {
        vector<bool> repeat(256);
        for (int j=i;j<n;j++) 
        {
            if (repeat[s[j]] == true)
                break;
            
            else {
                ans = max(ans, j - i + 1);
                repeat[s[j]] = true;
            }
        }
        repeat[s[i]] = false;
    }
        
    return ans;
    }
};