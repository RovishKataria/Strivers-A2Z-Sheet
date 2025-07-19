// https://www.geeksforgeeks.org/problems/number-of-islands/1
// https://www.naukri.com/code360/problems/number-of-islands-ii_1266048
// https://www.naukri.com/code360/problems/largest-island_840701
// https://www.youtube.com/watch?v=Rn6B-Q4SNyA

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int cnt = 0;
        vector<int> ans;
        for (auto it:operators) {
            int row = it[0];
            int col = it[1];
            if (visited[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            for (int i=0; i<4; i++) {
                int nrow = row + delta_row[i];
                int ncol = col + delta_col[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visited[nrow][ncol] == 1) {
                        int node = row * m + col;
                        int adj_node = nrow * m + ncol;
                        if (ds.findUPar(node) != ds.findUPar(adj_node)) {
                            cnt--;
                            ds.unionBySize(node, adj_node);
                        }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
