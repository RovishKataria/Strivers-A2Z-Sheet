// https://www.naukri.com/code360/problems/implement-queue-using-linked-list_8161235
// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
// https://www.youtube.com/watch?v=tqQ5fTamIN4

/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

void Queue::push(int x) {
    Node* temp = new Node(x);
    if (front == NULL) front = rear = temp;
    else {
        rear->next = temp;
        rear = rear->next;
    }
}

int Queue::pop() {
    if (front == NULL) return -1;
    Node* temp = front;
    int elem = temp->data;
    front = front->next;
    delete temp;
    if (front == NULL) rear = NULL;
    return elem;
}