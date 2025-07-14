// https://www.geeksforgeeks.org/problems/alien-dictionary/1
// https://www.youtube.com/watch?v=U3N_je7tWAs

class Solution {
  private:
    vector<int> topoSort(int V, vector<vector<int>>& adjList) {
        vector<int> indegree(V, 0);
        for (int i=0; i<V; i++) {
            for (auto it:adjList[i]) indegree[it]++;
        }
        
        queue<int> q;
        for (int i=0; i<indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto it:adjList[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // Check for cycle
        if (ans.size() != V) return {};  // cycle detected
        return ans;
    }
  public:
    string findOrder(vector<string> &words) {
        unordered_set<char> unique_char;
        for (auto word:words) {
            for (auto ch:word) {
                unique_char.insert(ch);
            }
        }
        
        int V = unique_char.size();
        // size 26 for all alphabets
        vector<vector<int>> adjList(26);
        vector<bool> present(26, false);
        
        for (auto ch:unique_char) {
            present[ch - 'a'] = true;
        }
        
        // build graph
        for (int i=0; i<words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            
            // Handle invalid case (e.g. "abc", "ab")
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2) {
                return "";  // Invalid order
            }
            
            int n = min(s1.size(), s2.size());
            for (int j=0; j<n; j++) {
                if (s1[j] != s2[j]) {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adjList[u].push_back(v);
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adjList);
        if (topo.empty()) return "";  // cycle or invalid order
        
        string ans = "";
        for (auto it:topo) {
            if (present[it]) ans += char(it + 'a');
        }
        return ans;
    }
};