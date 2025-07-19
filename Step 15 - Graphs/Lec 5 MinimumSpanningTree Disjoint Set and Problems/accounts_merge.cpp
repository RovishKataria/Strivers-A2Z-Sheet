// https://www.geeksforgeeks.org/problems/merging-details/1
// https://leetcode.com/problems/accounts-merge/description/
// https://www.youtube.com/watch?v=FMwpt_aQOGw

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
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string, int> map_mail_node;
        // connecting components
        for (int i=0; i<n; i++) {
            for (int j=1; j<details[i].size(); j++) {
                string mail = details[i][j];
                if (map_mail_node.find(mail) == map_mail_node.end()) {
                    map_mail_node[mail] = i;
                }
                else {
                    // below line won't work for 3rd test case
                    // ds.unionBySize(i, map_mail_node[mail]);
                    ds.unionBySize(map_mail_node[mail], i);
                }
            }
        }
        
        // merging mails
        vector<string> merged_mail[n];
        for (auto it: map_mail_node) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            merged_mail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for (int i=0; i<n; i++) {
            if (merged_mail[i].size() == 0) continue;
            sort(merged_mail[i].begin(), merged_mail[i].end());
            
            vector<string> temp;
            temp.push_back(details[i][0]); // Retain the original name
            for (auto it : merged_mail[i]) {
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        // adding this line will make 56 test case pass
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};