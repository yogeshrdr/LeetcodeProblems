class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<s1.length();i++)
            mp[s1[i]]++;
        
        int count=mp.size();
        
        int i=0,j=0;
        
        while(j<s2.length()){
            
            if(mp.find(s2[j])!=mp.end()){
                mp[s2[j]]--;
                
                if(mp[s2[j]]==0)
                    count--;
            }
            
            j++;
            
            while(count==0){
                
                if(mp.find(s2[i])!=mp.end()){
                    mp[s2[i]]++;
                
                    if(mp[s2[i]]>0)
                        count++;
                }
                
                if((j-i)==s1.length())
                    return true;
                
                i++;
            }
        }
        
        return false;
    }
};