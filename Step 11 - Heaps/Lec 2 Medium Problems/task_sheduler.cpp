// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // {task, freq}
        unordered_map<char, int> freq;
        for (auto task : tasks) freq[task]++;

        // max_heap = {freq, task}
        priority_queue<pair<int, char>> max_heap;
        for (auto [task, f] : freq) max_heap.push({f, task});
        
        // {available_time, {freq, task}}
        queue<pair<int, pair<int, char>>> cooldown;

        // time to hold the current time of CPU
        int curr_time = 0;
        while (!max_heap.empty() || !cooldown.empty()) {
            curr_time++;
            // first check if cooldown front has time which is equal to current time
            if (!cooldown.empty() && cooldown.front().first == curr_time) {
                // push into maxHeap so that it can be printed at current time or
                // anywhere after current time
                max_heap.push(cooldown.front().second);
                cooldown.pop();
            }
            if (!max_heap.empty()) {
                // getting the top to print it
                auto [fre, task] = max_heap.top();
                max_heap.pop();

                fre--; // printed current task
                if (fre > 0) {
                    // push into cooldown for the time = current time + n + 1
                    cooldown.push({curr_time + n + 1, {fre, task}});
                }
            }
        }
        return curr_time;
    }
};