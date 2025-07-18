// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// https://www.youtube.com/watch?v=PATgNiuTP20&t=626s

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjList(V);
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        set<pair<int, int>> st;
        st.insert({0, src});
        
        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for (auto it:adjList[node]) {
                int adj_node = it.first;
                int edge_wt = it.second;
                
                if (dis + edge_wt < dist[adj_node]) {
                    // erase if existed
                    if (dist[adj_node] != 1e9)
                        st.erase({dist[adj_node], adj_node});
                    dist[adj_node] = dis + edge_wt;
                    st.insert({dist[adj_node], adj_node});
                }
            }
        }
        
        return dist;
    }
};