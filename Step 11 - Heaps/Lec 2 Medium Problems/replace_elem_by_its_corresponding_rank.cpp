// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

typedef pair<int, int> pi;
class Solution {
  public:
    vector<int> replaceWithRank(vector<int> &arr, int n) {
        priority_queue<pi, vector<pi>, greater<pi>> min_heap;
        for (int i=0; i<n; i++) {
            min_heap.push({arr[i], i});
        }
        vector<int> rank_arr(n);
        int current_rank = 0;
        int prev_val = -1;
        while (!min_heap.empty()) {
            auto it = min_heap.top();
            min_heap.pop();
            
            int ind = it.second;
            int elem = it.first;
            
            // If it's a new value, increment the rank
            if (elem != prev_val) {
                current_rank++;
                prev_val = elem;
            }

            // Assign the rank
            rank_arr[ind] = current_rank;
        }
        return rank_arr;
    }
};
