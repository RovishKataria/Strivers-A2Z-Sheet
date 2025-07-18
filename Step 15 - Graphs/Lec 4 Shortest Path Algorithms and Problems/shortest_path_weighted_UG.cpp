// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// https://www.youtube.com/watch?v=rp1SMw7HSO8

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        int src = 1;
        int dest = n;
        vector<vector<pair<int, int>>> adjList(n+1);
        for (int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(n+1, 1e9), parent(n+1);
        dist[src] = 0;
        for (int i=1; i<=n; i++) parent[i] = i;
        
        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            
            for (auto it:adjList[node]) {
                int adj_node = it.first;
                int edge_wt = it.second;
                if (dis + edge_wt < dist[adj_node]) {
                    dist[adj_node] = dis + edge_wt;
                    pq.push({dist[adj_node], adj_node});
                    parent[adj_node] = node;
                }
            }
        }
        
        if (dist[dest] == 1e9) return {-1};
        
        vector<int> path;
        int node=dest;
        // TC = O(n)
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[dest]);
        return path;
    }
};