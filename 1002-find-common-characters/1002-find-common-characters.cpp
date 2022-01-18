class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        if (words.size() == 1) 
            return words;
        
        unordered_map<char, int> mp, temp;
        
        for (auto c : words[0]) 
            mp[c]++;
       
        for (int i = 1; i < words.size(); i++) {
            for (auto &j : words[i])          
                if (mp[j]) { 
                    temp[j]++; 
                    mp[j]--; 
                } 
            
            mp = temp;
            temp.clear();
        }
        
        vector<string> ans; 
        string str = "";
        
        for (auto i : mp) 
            while(i.second--) { 
                str += i.first; 
                ans.push_back(str); 
                str = ""; 
            } 
        
        return ans;
    }
};