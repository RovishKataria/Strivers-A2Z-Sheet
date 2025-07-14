// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// https://www.youtube.com/watch?v=iTBaI90lpDQ

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(V);
        vector<int> indegree(V, 0);
        
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for (auto it:adjList[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        if (cnt == V) return false;
        return true;
    }
};