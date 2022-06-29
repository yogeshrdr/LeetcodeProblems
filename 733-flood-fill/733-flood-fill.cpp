class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j,int val, int newColor){
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
            return;
        
        image[i][j] = newColor;
        solve(image,i-1,j,val,newColor);
        solve(image,i+1,j,val,newColor);
        solve(image,i,j-1,val,newColor);
        solve(image,i,j+1,val,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image[sr][sc];
        solve(image, sr, sc, x, newColor);
        return image;
    }
};