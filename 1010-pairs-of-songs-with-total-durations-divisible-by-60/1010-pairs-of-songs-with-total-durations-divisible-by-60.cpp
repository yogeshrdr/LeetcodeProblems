class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> mp;
        
        int count = 0;
        
        for(int i=0;i<time.size();i++){
            int x = time[i]%60;
            
            if(x == 0)
                count += mp[0];
            else
                count += mp[60 - x];
            
            mp[time[i]%60]++;
        }
        
        return count;
        
    }
};