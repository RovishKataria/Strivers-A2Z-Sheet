// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// https://www.youtube.com/watch?v=ZUFQfFaU-8U

class Solution {
  private:
    // topo sort using DFS
    void topoSort(int node, vector<vector<pair<int, int>>>& adjList,
    vector<int>& visited, stack<int>& st) {
        visited[node] = 1;
        for (auto it:adjList[node]) {
            int v = it.first;
            if (!visited[v]) topoSort(v , adjList, visited, st);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjList(V);
        for (int i=0; i<E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
        }
        
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i=0; i<V; i++) {
            if (!visited[i]) topoSort(i, adjList, visited, st);
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            for (auto it:adjList[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i=0; i<dist.size(); i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
