// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
// https://leetcode.com/problems/critical-connections-in-a-network/description/
// https://www.youtube.com/watch?v=qrAub5z8FeA

class Solution {
private:
    int timer = 1;
    
    void dfs(int node, int parent, vector<int>& visited,
             vector<vector<int>>& adjList, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& bridges) {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto it : adjList[node]) {
            if (it == parent) continue;
            if (visited[it] == 0) {
                dfs(it, node, visited, adjList, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // node --- it can be a bridge only if below is true
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                // bridge not possible
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for (auto it:connections) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> visited(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, visited, adjList, tin, low, bridges);
        return bridges;
    }
};

// gfg sol
class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& visited,
             vector<vector<int>>& adjList, vector<int>& tin, vector<int>& low,
             vector<vector<int>>& bridges) {
        visited[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for (auto it : adjList[node]) {
            if (it == parent) continue;
            if (!visited[it]) {
                dfs(it, node, visited, adjList, tin, low, bridges);
                low[node] = min(low[node], low[it]);
                // node --- it can be a bridge only if below is true
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                // bridge not possible
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    bool isBridge(int n, vector<vector<int>>& connections, int c, int d) {
        vector<vector<int>> adjList(n);
        for (auto it : connections) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, -1, visited, adjList, tin, low, bridges);
            }
        }

        for (auto& bridge : bridges) {
            if ((bridge[0] == c && bridge[1] == d) || (bridge[0] == d && bridge[1] == c)) {
                return true;
            }
        }

        return false;
    }
};
