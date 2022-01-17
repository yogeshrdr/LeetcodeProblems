class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> mp;

        for(auto i:t)
            mp[i]++;
        
        int count=mp.size();

        int i=0,j=0, len=INT_MAX;
        string str="";
       
        while(j<s.length()){
            
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)
                count--;
            }   
            
            if(count>0) 
                j++;

            else if(count==0){
                if(j-i+1 < len){
                    len = j-i+1;
                    str = s.substr(i ,len);
                }
              
                while(count==0){
                    if(mp.find(s[i])==mp.end()){
                        i++;
                        if(j-i+1 < len){
                            len = j-i+1;
                            str = s.substr(i ,len);
                         } 
                   
                    }
                              
                    else {
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            i++;
                            count++;
                        }
                        else{
                            i++;
                            if(j-i+1 < len){
                                len = j-i+1;
                                str = s.substr(i ,len);
                            }
                        }
                    }
                }
                j++; 
            }
        }
        
        return str;
    }
};