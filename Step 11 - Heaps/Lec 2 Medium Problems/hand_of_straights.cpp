// https://leetcode.com/problems/hand-of-straights/description/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());
        map<int, int> freq;
        for (auto card : hand) freq[card]++;

        while (!freq.empty()) {
            int start = freq.begin()->first;
            for (int i=0; i<groupSize; i++) {
                int card = start + i;
                if (freq[card] == 0) return false;

                freq[card]--;
                if (freq[card] == 0) freq.erase(card);
            }
        }
        return true;
    }
};

// using heap
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (auto card : hand) freq[card]++;

        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto [card, count] : freq) min_heap.push(card);

        while (!min_heap.empty()) {
            int first = min_heap.top();
            for (int i=0; i<groupSize; i++) {
                int curr = first + i;
                if (freq[curr] == 0) return false;
                freq[curr]--;

                if (min_heap.top() == curr && freq[curr] == 0)
                    min_heap.pop();
            }

            while (!min_heap.empty() && freq[min_heap.top()] == 0)
                min_heap.pop();
        }
        return true;
    }
};