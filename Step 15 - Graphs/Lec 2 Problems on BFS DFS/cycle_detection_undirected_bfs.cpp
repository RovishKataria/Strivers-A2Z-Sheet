// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://www.youtube.com/watch?v=BPlrALf1LDU

class Solution {
  private:
    bool detect(int src, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adj_node : adjList[node]) {
                if (!visited[adj_node]) {
                    visited[adj_node] = 1;
                    q.push({adj_node, node});
                }
                else if (adj_node != parent) {
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Build the adjList from the list of edges
        vector<vector<int>> adjList(V);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int> visited(V, 0);
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (detect(i, adjList, visited)) return true;
            }
        }
        return false;
    }
};