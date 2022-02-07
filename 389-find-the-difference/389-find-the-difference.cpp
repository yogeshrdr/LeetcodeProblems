class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        
        for(auto i: s)
            mp[i]++;
        
        char ans;
        
        for(int i=0;i<t.size();i++){
            if(mp.find(t[i])==mp.end()){
                ans = t[i];
                break;
            }else{
                mp[t[i]]--;
                if(mp[t[i]] == 0)
                    mp.erase(t[i]);
            }
        }
        
        return ans;
    }
};