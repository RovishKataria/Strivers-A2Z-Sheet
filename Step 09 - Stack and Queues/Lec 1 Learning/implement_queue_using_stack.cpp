// https://www.naukri.com/code360/problems/queue-using-stack_799482
// https://www.geeksforgeeks.org/problems/queue-using-two-stacks/1
// https://leetcode.com/problems/implement-queue-using-stacks/description/
// https://www.youtube.com/watch?v=tqQ5fTamIN4

class Queue {
    stack<int> s1, s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if (s1.empty()) return -1;
        int elem = s1.top();
        s1.pop();
        return elem;
    }

    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

// if push operations are far far greater than top, pop
class Queue {
    stack<int> s1, s2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }
    
    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        if (s2.empty()) {
            if (s1.empty()) return -1;
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int elem = s2.top();
        s2.pop();
        return elem;
    }

    int peek() {
        if (s2.empty()) {
            if (s1.empty()) return -1;
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};