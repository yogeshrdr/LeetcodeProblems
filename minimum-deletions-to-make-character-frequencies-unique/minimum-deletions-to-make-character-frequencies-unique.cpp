class Solution {
public:
    int minDeletions(string s) {
       vector<int> cnt(26);
        
       for(int i=0;i<s.size();i++){
          cnt[s[i]-'a']++;
       } 
        
        sort(cnt.begin(), cnt.end());
        
        int ans = 0;
        
        for (int i=1;i<cnt.size();i++){
            int j = i;
            while (j>0 && cnt[j] == cnt[j-1] && cnt[j-1]>0){
                cnt[j - 1]--;
			    ans++;
			    j--;
            } 
        }
        return ans;
    }
};