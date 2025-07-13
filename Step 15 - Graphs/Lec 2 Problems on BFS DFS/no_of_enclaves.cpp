// https://leetcode.com/problems/number-of-enclaves/description/
// https://www.geeksforgeeks.org/problems/number-of-enclaves/1
// https://www.youtube.com/watch?v=rxKcepXQgU4

class Solution {
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if (grid[i][j]) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol]) {
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                    }
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] && !visited[i][j]) cnt++;
            }
        }
        return cnt;
    }
};