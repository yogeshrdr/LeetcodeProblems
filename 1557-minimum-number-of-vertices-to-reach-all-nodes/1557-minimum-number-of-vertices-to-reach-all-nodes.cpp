class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> temp(n);
        
        for(auto i: edges)
            temp[i[1]]++;
        
        for(int i=0;i<temp.size();i++)
            if(temp[i] == 0)
                ans.push_back(i);
        
        return ans;
    }
};