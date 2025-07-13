// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626
// https://www.youtube.com/watch?v=9twcmtQj4DU

class Solution {
  private:
    bool dfsCheck(int node, vector<vector<int>>& adjList,
    vector<int>& visited, vector<int>& path_visited) {
        visited[node] = 1;
        path_visited[node] = 1;
        
        for (auto it:adjList[node]) {
            // if not visited
            if (!visited[it]) {
                if (dfsCheck(it, adjList, visited, path_visited))
                    return true;
            }
            // if visited and also path visited
            else if (path_visited[it]) return true;
        }
        path_visited[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        // AdjList for directed graph
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }
        
        vector<int> visited(V, 0);
        vector<int> path_visited(V, 0);
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) {
                if (dfsCheck(i, adjList, visited, path_visited))
                    return true;
            }
        }
        return false;
    }
};