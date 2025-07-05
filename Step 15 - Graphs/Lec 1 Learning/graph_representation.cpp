// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
// https://www.youtube.com/watch?v=3oI-34aPMWM

#include <iostream>
using namespace std;

// // Adj matrix
// int main() {
//     int n, m;
//     cin >> n >> m;
//     // graph here
//     int adj[n+1][n+1];
//     for (int i=0; i<m; i++) {
//         int u, v;
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//         // if weighted graph then below
//         // adj[u][v] = wt;
//         // adj[v][u] = wt;
//     }
//     return 0;
// }

// Adj List
int main() {
    int n, m;
    cin >> n >> m;
    // graph here
    vector<vector<int>> adj(n+1);
    // Weighted graph
    // vector<pair<int, int>> adj(n+1);
    for (int i=0; i<m; i++) {
        int u, v;
        // u ---> v
        cin >> u >> v;
        adj[u].push_back(v);
        // Comment out if undirected
        // adj[v].push_back(u);
    }
    return 0;
}