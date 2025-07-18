// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// https://www.youtube.com/watch?v=V6H1qAeB-l4&t=448s

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for (auto it:adjList[node]) {
                int adj_node = it.first;
                int edge_wt = it.second;
                
                if (dis + edge_wt < dist[adj_node]) {
                    dist[adj_node] = dis + edge_wt;
                    pq.push({dist[adj_node], adj_node});
                }
            }
        }
        return dist;
    }
};