// https://leetcode.com/problems/rotting-oranges/description/
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1
// https://www.youtube.com/watch?v=yf3oUhkvqA0

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int rotten[n][m];
        int cntFresh = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 2) {
                    q.push({{i, j}, 0});
                    rotten[i][j] = 2;
                }
                else {
                    rotten[i][j] = 0;
                }
                if (mat[i][j] == 1) cntFresh++;
            }
        }
        
        int max_time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            max_time = max(max_time, t);
            q.pop();
            for (int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    rotten[nrow][ncol] != 2 && 
                    mat[nrow][ncol] == 1) {
                        q.push({{nrow, ncol}, t + 1});
                        rotten[nrow][ncol] = 2;
                        cnt++;
                    }
            }
        }
        
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<m; j++) {
        //         if (rotten[i][j] != 2 && mat[i][j] == 1) return -1;
        //     }
        // }
        
        if (cnt != cntFresh) return -1;
        return max_time;
    }
};