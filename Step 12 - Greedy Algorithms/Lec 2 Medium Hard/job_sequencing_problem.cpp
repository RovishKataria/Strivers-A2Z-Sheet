// https://www.naukri.com/code360/problems/job-sequencing-problem_1169460
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// https://www.youtube.com/watch?v=QbwltemZbRg

#include<bits/stdc++.h>
bool comp(vector<int>& job1, vector<int>& job2) {
    return (job1[2] > job2[2]);
}
vector<int> jobScheduling(vector<vector<int>> &jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    
    // // Sort by profit descending using lambda
    // sort(jobs.begin(), jobs.end(),
    //     [](const vector<int>& a, const vector<int>& b)
    //     { return a[2] > b[2]; }
    // );
    
    int total_profit = 0;
    int total_jobs = 0;
    int max_deadline = -1;
    for (int i=0; i<n; i++) max_deadline = max(max_deadline, jobs[i][1]);
    
    vector<int> hash(max_deadline+1, -1);
    for (int i=0; i<n; i++) {
        for (int j=jobs[i][1]; j>0; j--) {
            if (hash[j] == -1) {
                hash[j] = jobs[i][0];
                total_profit += jobs[i][2];
                total_jobs++;
                break;
            }
        }
    }
    return {total_jobs, total_profit};
}

// Using DSU to optimize the j-loop
#include<bits/stdc++.h>
bool comp(vector<int>& job1, vector<int>& job2) {
    return (job1[2] > job2[2]);
}
int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}
vector<int> jobScheduling(vector<vector<int>> &jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    
    int total_profit = 0;
    int total_jobs = 0;
    int max_deadline = -1;
    for (int i=0; i<n; i++) max_deadline = max(max_deadline, jobs[i][1]);
    
    vector<int> parent(max_deadline + 1);
    // Initialize DSU parent array
    for (int i = 0; i <= max_deadline; i++) parent[i] = i;

    for (int i=0; i<n; i++) {
        int free_slot = find(jobs[i][1], parent);
        if (free_slot > 0) {
            // Assign the job and update DSU
            total_jobs++;
            total_profit += jobs[i][2];
            parent[free_slot] = find(free_slot - 1, parent);
        }
    }
    return {total_jobs, total_profit};
}