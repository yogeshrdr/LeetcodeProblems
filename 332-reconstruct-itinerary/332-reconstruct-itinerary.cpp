class Solution {
public:
    void dfs(string curr, vector<string> &ans, unordered_map<string, priority_queue<string,vector<string>,greater<string>>> &mp){
    
        auto &x = mp[curr];
    
        while(!x.empty()){
            string next = x.top();
            x.pop();
            dfs(next,ans,mp);
        }
    
        ans.push_back(curr);
    }
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string,vector<string>,greater<string>>> mp;
        
        vector<string> ans;
    
        for(auto i: tickets)
            mp[i[0]].push(i[1]);
        
        dfs("JFK", ans, mp);
        
        reverse(ans.begin(), ans.end());
        return ans;    
    }
};