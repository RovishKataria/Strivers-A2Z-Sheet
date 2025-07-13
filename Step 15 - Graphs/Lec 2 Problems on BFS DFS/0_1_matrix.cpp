// Leetcodehas some different question but same approach
// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// https://leetcode.com/problems/01-matrix/
// https://www.youtube.com/watch?v=edXdVwkYHF8

// GFG solution
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                // Use below line for leetcode submission
                // if (grid[i][j] == 0) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            distance[row][col] = steps;
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            
            for (int i=0; i<4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !visited[nrow][ncol]) {
                    q.push({{nrow, ncol}, steps+1});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return distance;
    }
};