class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() <=1)
            return intervals;
        
        vector<vector<int>> ans;
        
        sort(intervals.begin(), intervals.end());
        
        int i=1,j=0;
        ans.push_back(intervals[0]);
        
        while(i<intervals.size()){
            if(ans[j][1] >= intervals[i][0]) 
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            else{
                ans.push_back(intervals[i]);
                j++;
            }
                
            i++;
        }
        
        return ans;
    }
};