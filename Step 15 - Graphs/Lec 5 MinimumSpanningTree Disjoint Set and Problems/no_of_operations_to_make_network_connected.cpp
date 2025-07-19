// https://www.geeksforgeeks.org/problems/connecting-the-graph/1
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// https://www.youtube.com/watch?v=FYrl7iz9_ZU

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i=0; i<=n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        // path compression
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extra_edges = 0;
        for (auto it:edge) {
            int u = it[0];
            int v = it[1];
            // extra edge
            if (ds.findUPar(u) == ds.findUPar(v)) extra_edges++;
            else ds.unionBySize(u, v);
        }
        int no_comp = 0;
        for (int i=0; i<n; i++) if (ds.parent[i] == i) no_comp++;
        if (extra_edges >= no_comp-1) return no_comp-1;
        return -1;
    }
};
