// https://leetcode.com/problems/find-eventual-safe-states/description/
// https://www.geeksforgeeks.org/problems/eventual-safe-states/1
// https://www.youtube.com/watch?v=2gtg3VsDGyc

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        // reverse all the edges
        for (int i=0; i<V; i++) {
            // current : i -> it
            // we want : it -> i
            for (auto it:adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> safe_nodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe_nodes.push_back(node);
            for (auto it:adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};
