// https://leetcode.com/problems/number-of-provinces/description/
// https://www.youtube.com/watch?v=ACzkVtewUYA

class Solution {
private:
    void dfs_traversal(int node, const vector<vector<int>> adjList,
                       vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it])
                dfs_traversal(it, adjList, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> visited(adjList.size(), 0);
        int provinces = 0;
        for (int i = 0; i < adjList.size(); i++) {
            if (!visited[i]) {
                dfs_traversal(i, adjList, visited);
                provinces++;
            }
        }
        return provinces;
    }
};