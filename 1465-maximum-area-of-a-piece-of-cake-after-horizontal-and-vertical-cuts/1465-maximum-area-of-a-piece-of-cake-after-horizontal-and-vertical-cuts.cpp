class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
		
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        int maxheight = max(horizontalCuts[0], h - horizontalCuts[n-1]);
        int maxwidth = max(verticalCuts[0] , w - verticalCuts[m-1]);
        
        for(int i=0;i<n-1;i++)
            maxheight = max(maxheight, horizontalCuts[i+1] - horizontalCuts[i]);
        
        for(int i=0;i<m-1;i++)
            maxwidth = max(maxwidth, verticalCuts[i+1] - verticalCuts[i]);
        
        long long mod = 1000000007;
        
        int ans = ((maxwidth % mod) * (maxheight%mod)) % mod;
        return ans;
        
    }
};