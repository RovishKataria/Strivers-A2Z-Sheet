// https://leetcode.com/problems/course-schedule-ii/description/
// https://www.geeksforgeeks.org/problems/course-schedule/1
// https://www.youtube.com/watch?v=WAOfKpxYHR8

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses);
        for (int i=0; i<prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adjList[u].push_back(v);
            indegree[v]++;
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
        if (ans.size() == numCourses) return ans;
        return {};
    }
};