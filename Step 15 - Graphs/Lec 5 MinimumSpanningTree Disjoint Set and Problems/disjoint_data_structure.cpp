#include "bits/stdc++.h"
using namespace std;

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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    
    // if (ds.findUPar(3) == ds.findUPar(7)) cout << "same\n";
    // else cout << "not same\n";
    
    // ds.unionByRank(3, 7);

    // if (ds.findUPar(3) == ds.findUPar(7)) cout << "same\n";
    // else cout << "not same\n";

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    if (ds.findUPar(3) == ds.findUPar(7)) cout << "same\n";
    else cout << "not same\n";
    
    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) cout << "same\n";
    else cout << "not same\n";
    return 0;
}