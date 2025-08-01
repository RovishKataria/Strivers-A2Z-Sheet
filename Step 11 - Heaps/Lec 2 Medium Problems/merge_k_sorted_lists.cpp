// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 struct compare{
    bool operator()(ListNode* val1, ListNode* val2) {
        return val1->val > val2->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;
        for (int i=0; i<k; i++) {
            if (lists[i] != NULL) min_heap.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!min_heap.empty()) {
            ListNode* temp = min_heap.top();
            min_heap.pop();
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            if (temp->next != NULL) min_heap.push(temp->next);
        }
        return head;
    }
};