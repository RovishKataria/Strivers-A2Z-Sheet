// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// https://www.youtube.com/watch?v=Qzf1a--rhp8
// SC = O(n) + O(n) + O(n) ~ O(n)
// TC = 
class Solution {
  public:
    void dfs_traversal(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it:adj[node]) {
            if (!vis[it]) dfs_traversal(it, vis, adj, ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> vis(adj.size(), 0);
        vector<int> ans;
        dfs_traversal(0, vis, adj, ans);
        return ans;
    }
};