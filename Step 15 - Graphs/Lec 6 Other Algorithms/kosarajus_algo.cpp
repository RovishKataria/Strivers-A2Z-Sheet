// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// https://www.youtube.com/watch?v=R6uoSjZ2imo

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (auto it:adj[node]) {
            if (!visited[it]) dfs(it, adj, visited, st);
        }
        st.push(node);
    }
    
    void dfs3(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;
        for (auto it:adjList[node]) {
            if (!visited[it]) dfs3(it, adjList, visited);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;
        // step1: sort all edges acc to finish time
        // O( V + E)
        for (int i=0; i<V; i++) {
            if (!visited[i]) dfs(i, adj, visited, st);
        }
        
        // step2: reverse graph
        // O( V + E)
        vector<vector<int>> adjList(V);
        for (int u=0; u<adj.size(); u++) {
            visited[u] = 0;
            for (auto v:adj[u]) {
                adjList[v].push_back(u);
            }
        }
        
        // step3: do DFS on reversed graph using sorted edges
        // visited.resize(V, 0);
        // O( V + E)
        int scc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                scc++;
                dfs3(node, adjList, visited);
            }
        }
        return scc;
    }
};