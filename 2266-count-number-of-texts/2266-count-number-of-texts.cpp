class Solution {
public:
    vector<int> apl = {0,0,3,3,3,3,3,4,3,4};
    const int mod = 1000000007;
    
   int solve(int x, int sum, vector<int>&temp){
        if(sum == 0)
            return 1;
        
        if(sum == 1)
            return 1;
        
        if(sum == 2)
            return 2;
        
        if(temp[sum] != -1)
            return temp[sum];
        
        long int ans = 0;
        int y = apl[x];
        
        for(int i=1;i<=y;i++){
            int z = sum;
            if(sum>=i){
                sum -= i;
                ans += solve(x, sum, temp)%mod;
                temp[z] = ans%mod;
                sum += i;
            }
        }
        
        return ans % mod;
    }
    
    
    
    
    int mapvector(int x, int count, unordered_map<int, vector<int>>&mp){  
        if(mp.find(x)==mp.end()){
            mp[x].resize(1000000, -1);
        }
                
        auto&temp = mp[x];
        
        if(mp.find(x)!=mp.end() && temp[count]!=-1)
            return temp[count]%mod;
                
        else
            return solve(x, count, temp)%mod;
        
        return 1;
    }
    
    
    int countTexts(string pressedKeys) {
        long int ans=1;
        int count=1;
        
        unordered_map<int, vector<int>> mp;
        
        for(int i=1;i<pressedKeys.size();i++){
            if(pressedKeys[i-1]!=pressedKeys[i]){
                int x = pressedKeys[i-1] - '0';
                ans = (ans * mapvector(x, count, mp)) % mod;
                count = 0;
            }
            
            count++;
        }
        
        int x = pressedKeys[pressedKeys.length()-1] - '0';
        ans = (ans * mapvector(x, count, mp))%mod;
        
        return ans%mod;
        
    }
};