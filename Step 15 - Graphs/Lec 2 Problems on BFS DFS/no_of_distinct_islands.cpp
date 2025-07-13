// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// https://www.youtube.com/watch?v=7zmgQSJghpo

class Solution {
  private:
    void dfs(int row, int col, int row0, int col0, vector<vector<int>>& grid, 
    vector<vector<int>>& visited, vector<pair<int, int>>& vec) {
        visited[row][col] = 1;
        vec.push_back({row - row0, col - col0});
        int n = grid.size();
        int m = grid[0].size();
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        for (int i=0; i<4; i++) {
            int nrow = row + delta_row[i];
            int ncol = col + delta_col[i];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                dfs(nrow, ncol, row0, col0, grid, visited, vec);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, i, j, grid, visited, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
