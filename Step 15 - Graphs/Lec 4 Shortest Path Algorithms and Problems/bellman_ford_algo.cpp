// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// https://www.youtube.com/watch?v=0vVofAhAYjc

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        // relaxation loop for N-1 times
        for (int relax=0; relax<V; relax++) {
            for (int i=0; i<edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // relaxing for Nth time to check for -ve weight cycle
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) return {-1};
        }
        
        return dist;
    }
};
