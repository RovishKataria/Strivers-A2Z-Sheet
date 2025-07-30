// https://www.geeksforgeeks.org/problems/jump-game/1
// https://leetcode.com/problems/jump-game/
// https://www.youtube.com/watch?v=tZAa_jJ3SwQ

class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        int max_ind = 0;
        for (int i=0; i<n; i++) {
            if (i > max_ind) return false;
            max_ind = max(max_ind, i + arr[i]);
        }
        return true;
    }
};