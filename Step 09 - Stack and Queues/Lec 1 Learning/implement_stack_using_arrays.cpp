// https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209
// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1
// https://www.youtube.com/watch?v=tqQ5fTamIN4

class Stack {
private:
    int top_index, capacity;
    vector<int> data;
    
public:
    Stack(int capacity) {
        this->capacity = capacity;
        top_index = -1;
        data.resize(capacity);
    }

    void push(int num) {
        if (top_index < capacity-1) {
            top_index++;
            data[top_index] = num;
        }
    }

    int pop() {
        if (top_index == -1) return -1;
        int elem = data[top_index];
        top_index--;
        return elem;
    }
    
    int top() {
        if (top_index == -1) return -1;
        return data[top_index];
    }
    
    int isEmpty() {
        if (top_index == -1) return 1;
        return 0;
    }
    
    int isFull() {
        if (top_index == capacity-1) return 1;
        return 0;
    }
};
