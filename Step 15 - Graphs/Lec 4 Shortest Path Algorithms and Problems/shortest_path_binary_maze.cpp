// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
// https://www.youtube.com/watch?v=U5Mw4eyUmw4

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if (grid[destination.first][destination.second] != 1) return -1;
        if (source == destination) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            for (int i=0; i<4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 && dis+1 < dist[nrow][ncol]) {
                        if (nrow == destination.first &&
                            ncol == destination.second) return dis+1;
                        
                        dist[nrow][ncol] = dis+1;
                        q.push({dis+1, {nrow, ncol}});
                    }
            }
        }
        return -1;
    }
};

            
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        if (n == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // queue<{dist, {row, col}}> q
        queue<pair<int, pair<int, int>>> q;
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            int delta_row[] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int delta_col[] = {0, 1, 1, 1, 0, -1, -1, -1};
            for (int i=0; i<8; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis+1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dis+1;
                        
                        if (nrow == n-1 && ncol == n-1)
                            return dist[nrow][ncol];
                        
                        q.push({dis+1, {nrow, ncol}});
                    }
            }
        }
        return -1;
    }
};