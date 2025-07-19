// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://www.youtube.com/watch?v=ZSPjZuZWCME

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int sum = 0;
        vector<int> visited(V, 0);
        // {wt, node}
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        // E logE + E logE = E logE
        while (!pq.empty()) { // E
            auto it = pq.top(); // logE
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if (!visited[node]) {
                visited[node] = 1;
                sum += wt;
                // E logE
                for (auto it:adj[node]) {
                    int adj_node = it[0];
                    int edge_wt = it[1];
                    if (!visited[adj_node])
                        pq.push({edge_wt, adj_node});
                }
            }
        }
        return sum;
    }
};