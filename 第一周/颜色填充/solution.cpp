class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old_color = image[sr][sc];
        if(image[sr][sc] == newColor) 
            return image;
        image[sr][sc] = newColor;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int x = sr + dx[i], y = sc + dy[i];
            if(x >= 0 && y >= 0 && x < image.size() 
            && y < image[0].size() && image[x][y] == old_color)
                floodFill(image, x, y, newColor);
        }
        return image;
    }
};