// https://www.naukri.com/code360/problems/stack-using-queue_795152
// https://www.geeksforgeeks.org/problems/stack-using-two-queues/1
// https://leetcode.com/problems/implement-stack-using-queues/description/
// https://www.youtube.com/watch?v=tqQ5fTamIN4

class Stack {
	queue<int> q1, q2;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q2.push(element);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
};