// https://www.geeksforgeeks.org/problems/topological-sort/1
// https://www.youtube.com/watch?v=5lZ0iJMrUMk

class Solution {
  private:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited,
    stack<int>& st) {
        visited[node] = 1;
        for (auto it:adjList[node]) {
            if (!visited[it]) dfs(it, adjList, visited, st);
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(V);
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }
        vector<int> visited(V, 0);
        stack<int> st;
        
        for (int i=0; i<V; i++) {
            if (!visited[i]) dfs(i, adjList, visited, st);
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};