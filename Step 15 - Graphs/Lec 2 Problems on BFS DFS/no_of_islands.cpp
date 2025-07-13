// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
// https://www.youtube.com/watch?v=muncqlKJrH0

class Solution {
  private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // top, top-right, right, bottom-right, bottom, bottom-left, left, top-left
            int delta_row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int delta_col[] = {0, 1, 1, 1, 0, -1, -1, -1};
            
            for (int i=0; i<8; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    grid[nrow][ncol]=='L' && !visited[nrow][ncol]) {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
            }
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    cnt++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return cnt;
    }
};