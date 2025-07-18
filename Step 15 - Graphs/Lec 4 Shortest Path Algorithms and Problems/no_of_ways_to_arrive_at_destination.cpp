// https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
// https://www.youtube.com/watch?v=_-0mx0SmYxA

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i=0; i<roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adjList[u].push_back({v, t});
            adjList[v].push_back({u, t});
        }
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        int mod = (int)(1e9 + 7);
        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it:adjList[node]) {
                int adj_node = it.first;
                int edge_wt = it.second;
                // first time arrived with short distance
                if (dis + edge_wt < dist[adj_node]) {
                    dist[adj_node] = dis + edge_wt;
                    pq.push({dist[adj_node], adj_node});
                    ways[adj_node] = ways[node];
                }
                // if same distance
                else if (dis + edge_wt == dist[adj_node]) {
                    ways[adj_node] = (ways[adj_node] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};