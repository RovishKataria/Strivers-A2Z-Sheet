// https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// https://www.youtube.com/watch?v=9XybHVqTHcQ

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i=0; i<flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];
            adjList[u].push_back({v, price});
        }
        // pq{stops, {node, price}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> prices(n, 1e9);
        prices[src] = 0;
        q.push({0, {src, 0}});
        
        // TC = O(E)
        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            
            if (stops > K) continue;
            
            for (auto it:adjList[node]) {
                int adj_node = it.first;
                int p = it.second;
                if (price + p < prices[adj_node] && stops <= K) {
                    prices[adj_node] = price + p;
                    q.push({stops+1, {adj_node, prices[adj_node]}});
                }
            }
        }
        
        if (prices[dst] == 1e9) return -1;
        return prices[dst];
    }
};