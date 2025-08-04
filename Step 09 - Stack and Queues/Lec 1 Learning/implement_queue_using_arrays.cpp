// https://www.naukri.com/code360/problems/implement-queue-using-arrays_8390825
// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1
// https://www.youtube.com/watch?v=tqQ5fTamIN4

class Queue {
	int front, rear;
	vector<int> arr;

public:
	Queue() {
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e) {
		if (rear < 100001) arr[rear++] = e;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue() {
		if (front == rear) return -1;
		return arr[front++];
	}
};