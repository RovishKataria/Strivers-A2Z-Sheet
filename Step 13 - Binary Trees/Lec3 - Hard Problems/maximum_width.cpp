// https://leetcode.com/problems/maximum-width-of-binary-tree/description/
// https://www.youtube.com/watch?v=ZbybYvcVLks

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int siz = q.size();
            long long min_ind = q.front().second;
            long long first, last;
            for (int i=0; i<siz; i++) {
                long long curr_ind = q.front().second - min_ind;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = curr_ind;
                if (i == siz-1) last = curr_ind;
                if (node->left) q.push({node->left, curr_ind*2 + 1});
                if (node->right) q.push({node->right, curr_ind*2 + 2});
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};