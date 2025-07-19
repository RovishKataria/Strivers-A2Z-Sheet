// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://www.youtube.com/watch?v=DMnDM_sxVig

class DisjointSet {
    vector<int> rank, size, parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }
    
    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;
        // O(V + E)
        for (int u=0; u<V; u++) {
            for (auto it:adj[u]) {
                int v = it[0];
                int wt = it[1];
                edges.push_back({wt, {u, v}});
            }
        }
        DisjointSet ds(V);
        // O(M logM)
        sort(edges.begin(), edges.end());
        int mst_weight = 0;
        // O(M * 4 * alpha * 2)
        for (auto it:edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUPar(u) != ds.findUPar(v)) {
                mst_weight += wt;
                ds.unionBySize(u, v);
            }
        }
        return mst_weight;
    }
};