// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// https://leetcode.com/problems/surrounded-regions/description/
// https://www.youtube.com/watch?v=BtdgAys4yMk

class Solution {
  private:
    void dfsTraversal(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& mat) {
        visited[row][col] = 1;
        
        int n = mat.size();
        int m = mat[0].size();
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        
        for (int i=0; i<4; i++) {
            int nrow = row + delta_row[i];
            int ncol = col + delta_col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                mat[nrow][ncol] == 'O' && !visited[nrow][ncol])
                dfsTraversal(nrow, ncol, visited, mat);
        }
    }
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int j=0; j<m; j++) {
            // first row
            if (!visited[0][j] && mat[0][j] == 'O') {
                dfsTraversal(0, j, visited, mat);
            }
            // last row
            if (!visited[n-1][j] && mat[n-1][j] == 'O') {
                dfsTraversal(n-1, j, visited, mat);
            }
        }
        
        for (int i=0; i<n; i++) {
            // first col
            if (!visited[i][0] && mat[i][0] == 'O') {
                dfsTraversal(i, 0, visited, mat);
            }
            // last col
            if (!visited[i][m-1] && mat[i][m-1] == 'O') {
                dfsTraversal(i, m-1, visited, mat);
            }
        }
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 'O' && !visited[i][j])
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};