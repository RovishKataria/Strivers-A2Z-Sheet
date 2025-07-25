// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// https://www.youtube.com/watch?v=YbY8cVwWAvw

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // // if negative cycle
        // for (int i=0; i<n; i++) {
        //     for (int j=0; j<n; j++) {
        //         if (dist[i][j] < 0) "negative cycle";
        //     }
        // }
    }
};