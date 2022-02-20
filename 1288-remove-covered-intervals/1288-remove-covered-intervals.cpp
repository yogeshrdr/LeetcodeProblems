class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = intervals.size();
        
        if(count<2 )
            return count;
        
        sort( intervals.begin(), intervals.end());
        
        int i = 0, j = 1;
        
        while( i<intervals.size() && j< intervals.size() )
        {
            if( intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1] )
            {
                count--;
                j++;
            }
            else if( intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1] )
            {
                count--;
                i = j;
                j++;
            }
            else
            {
                i = j;
                j++;
            }
        }
        
        return count;    
    }
};