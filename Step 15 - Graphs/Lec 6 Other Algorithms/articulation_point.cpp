// https://www.geeksforgeeks.org/problems/articulation-point-1/1
// https://www.youtube.com/watch?v=j1QDfU21iZk

class Solution {
  private:
    int timer = 0;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited,
    vector<int>& tin, vector<int>& low, vector<int>& mark) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!visited[it]) {
                dfs(it, node, adj, visited, tin, low, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> tin(V);
        vector<int> low(V);
        vector<int> mark(V, 0);
        for (int i=0; i<V; i++) {
            if (!visited[i])
                dfs(i, -1, adj, visited, tin, low, mark);
        }
        
        vector<int> ans;
        for (int i=0; i<V; i++) {
            if (mark[i]) ans.push_back(i);
        }
        if (ans.size() == 0) return {-1};
        return ans;
    }
};