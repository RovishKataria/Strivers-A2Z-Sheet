// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// https://www.youtube.com/watch?v=zQ3zgFypzX4

class Solution {
  private:
    bool detect(int node, int parent, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                if (detect(it, node, adjList, visited)) return true;
            }
            else if (it != parent) return true;
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
                if (detect(i, -1, adjList, visited)) return true;
            }
        }
        return false;
    }
};