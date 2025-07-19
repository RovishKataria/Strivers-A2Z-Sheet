// https://www.geeksforgeeks.org/problems/maximum-connected-group/1
// https://leetcode.com/problems/making-a-large-island/description/
// https://www.youtube.com/watch?v=lgiz0Oup6gM

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
  private:
    bool isValid(int adjr, int adjc, int n) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // step 1 = connecting components
        for (int row=0; row<n; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col] == 1) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    for (int i=0; i<4; i++) {
                        int adjr = row + dr[i];
                        int adjc = col + dc[i];
                        if (isValid(adjr, adjc, n) && grid[adjr][adjc] == 1) {
                                int node = row * n + col;
                                int adj_node = adjr * n + adjc;
                                ds.unionBySize(node, adj_node);
                        }
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row=0; row<n; row++) {
            for (int col=0; col<n; col++) {
                if (grid[row][col] == 0) {
                    int dr[] = {-1, 0, 1, 0};
                    int dc[] = {0, 1, 0, -1};
                    set<int> components;
                    for (int i=0; i<4; i++) {
                        int adjr = row + dr[i];
                        int adjc = col + dc[i];
                        if (isValid(adjr, adjc, n) && grid[adjr][adjc] == 1) {
                                int node = row * n + col;
                                int adj_node = adjr * n + adjc;
                                // O(log n) = log4
                                components.insert(ds.findUPar(adj_node));
                        }
                    }
                    int sizeTotal = 0;
                    for (auto it:components) {
                        sizeTotal += ds.size[it];
                    }
                    mx = max(mx, sizeTotal+1);
                }
            }
        }
        for (int i=0; i<n*n; i++) {
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};
