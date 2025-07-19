// https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
// https://www.youtube.com/watch?v=OwMNX8SPavM

class DisjointSet {
    vector<int> rank, parent, size;
public:
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int max_row = 0, max_col = 0;
        for (auto it:stones) {
            max_row = max(max_row, it[0]);
            max_col = max(max_col, it[1]);
        }
        DisjointSet ds(max_row + max_col + 1);
        // map required to count unique valid components
        unordered_map<int, int> stoneNodes;
        for (auto it:stones) {
            int row = it[0];
            int col = it[1] + max_row + 1;
            ds.unionBySize(row, col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }
        int cnt = 0;
        for (auto it: stoneNodes) {
            if (ds.findUPar(it.first) == it.first) cnt++;
        }
        return n - cnt;
    }
};
