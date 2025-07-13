// https://www.geeksforgeeks.org/problems/bipartite-graph/1
// https://leetcode.com/problems/is-graph-bipartite/description/
// https://www.youtube.com/watch?v=KG5YFfR0j8A

// GFG
class Solution {
  private:
    bool check(int start, int V, vector<vector<int>>& adjList, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it:adjList[node]) {
                // if adjacent node is not colored
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if adjacent is same color
                else if (color[it] == color[node]) return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> color(V, -1);
        vector<vector<int>> adjList(V);
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for (int i=0; i<V; i++) {
            if (color[i] == -1) {
                if (check(i, V, adjList, color) == false) return false;
            }
        }
        return true;
    }
};

// Leetcode
class Solution {
  private:
    bool check(int start, int V, vector<vector<int>>& adjList, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it:adjList[node]) {
                // if adjacent node is not colored
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if adjacent is same color
                else if (color[it] == color[node]) return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(vector<vector<int>> &adjList) {
        int V = adjList.size();
        vector<int> color(V, -1);
        for (int i=0; i<V; i++) {
            if (color[i] == -1) {
                if (check(i, V, adjList, color) == false) return false;
            }
        }
        return true;
    }
};