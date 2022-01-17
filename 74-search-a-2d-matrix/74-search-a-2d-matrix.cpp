class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long i=0, j=matrix[0].size()-1;
        
        while(i<matrix.size() &&  j>=0){
            if(matrix[i][j] == target)
                return true;
            else if(target<matrix[i][j])
                j--;
            else 
                i++;
        }
        
        return false;
    }
};