class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(auto i: s)
            mp[i]++;
        
        int count = 0;
        bool flag = false;
        
        for(auto i: mp){
            if(i.second%2 == 0)
                count += i.second;
            else{
                count += i.second - 1;
                flag = true;
            }
                
        }
        
        return flag == true ? 1+count : count;
    }
};