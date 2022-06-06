class Solution {
public:
    int trap(vector<int>& height) {
        int i=0, j=height.size()-1;
        
        int ans = 0;
        int minHeight = 0;
        
        while(i<j){
            
            while(i<j && height[i]<=minHeight){
                ans += minHeight - height[i];
                i++;
            }
            
            while(i<j && height[j]<=minHeight){
                ans += minHeight - height[j];
                j--;
            }
            
            minHeight = min(height[i], height[j]);
            
        }
        
        return ans;
    }
};