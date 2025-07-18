// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1
// https://leetcode.com/problems/path-with-minimum-effort/description/
// https://www.youtube.com/watch?v=0ytpZyiZFhA

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<vector<int>> dist(rows, vector<int>(columns, 1e9));
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        // TC = O(E logV);
        // n x m x 4 x log(n x m);
        while (!pq.empty()) {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if (row == rows-1 && col == columns-1) return diff;
            
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            for (int i=0; i<4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < columns) {
                    int effort = max(abs(heights[nrow][ncol] - heights[row][col]), diff);
                    if (effort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
