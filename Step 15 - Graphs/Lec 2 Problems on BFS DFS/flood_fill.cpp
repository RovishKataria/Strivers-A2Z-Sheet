// https://leetcode.com/problems/flood-fill/description/
// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
// https://www.youtube.com/watch?v=C-2_uSRli8o

class Solution {
  private:
    void dfsTraversal(vector<vector<int>>& image, int row, int col, int newColor,
                      vector<vector<int>>& ans, int initial_color) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        for (int i=0; i<4; i++) {
            int nrow = row + delta_row[i];
            int ncol = col + delta_col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initial_color && ans[nrow][ncol] != newColor)
                dfsTraversal(image, nrow, ncol, newColor, ans, initial_color);
        }
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int initial_color = image[sr][sc];
        vector<vector<int>> ans = image;
        dfsTraversal(image, sr, sc, newColor, ans, initial_color);
        return ans;
    }
};