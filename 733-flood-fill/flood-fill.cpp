class Solution {
    void dfs(std::vector<std::vector<int>>& image, int r, int c, int initialColor, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != initialColor) {
            return;
        }
        
        image[r][c] = newColor;
        
        dfs(image, r + 1, c, initialColor, newColor); 
        dfs(image, r - 1, c, initialColor, newColor); 
        dfs(image, r, c + 1, initialColor, newColor); 
        dfs(image, r, c - 1, initialColor, newColor); 
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial_c = image[sr][sc];
        if (initial_c != color) {
            dfs(image, sr, sc, initial_c, color);
        }
        return image;
    }
};