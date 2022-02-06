class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        unordered_map<char, int> mp;
        
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i])
                bulls++;
            else
                mp[secret[i]]++;
        }
        
        for(int i=0;i<secret.size();i++){
            if (secret[i] != guess[i] && mp[guess[i]] > 0) {
			    mp[guess[i]]--;
			    cows++;
		    }
        }
        
        string b = to_string(bulls);
        string c =  to_string(cows);
        
        string ans = b + 'A' +c + 'B';
        return ans;
    }
};