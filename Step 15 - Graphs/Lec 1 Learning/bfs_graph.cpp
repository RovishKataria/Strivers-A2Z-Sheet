// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// https://www.youtube.com/watch?v=-tgVpUgsQ5k

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> vis(adj.size(), 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> ans;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto it:adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};