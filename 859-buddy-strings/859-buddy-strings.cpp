class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length()!=goal.length())
            return false;
        
        unordered_map<char, int> mp;
        
        for(auto m: s)
            mp[m]++;
        
        if(s == goal){
            for(auto m: mp)
                if(m.second > 1)
                    return true;
            
            return false; 
        }
            
        
        int n = s.length();
        int i=0, j=n-1;
        
        while(i<n && s[i] == goal[i])
            i++;
        
        while(j>=0 && s[j] == goal[j])
            j--;
        
        if(i!=j)
            swap(s[i], s[j]);
        
        return s == goal; 
    }
};