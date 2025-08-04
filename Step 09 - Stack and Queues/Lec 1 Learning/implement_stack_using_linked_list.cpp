// https://www.naukri.com/code360/problems/implement-stack-with-linked-list_630475
// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
// https://www.youtube.com/watch?v=tqQ5fTamIN4

/****************************************************************
    Following is the class structure of the Node class:
        class Node {
        public:
            int data;
            Node *next;
            Node() {
                this->data = 0;
                next = NULL;
            }
            Node(int data) {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next) {
                this->data = data;
                this->next = next;
            }
        };
*****************************************************************/

class Stack {
    Node* top;
    int siz;

public:
    Stack() {
        top = NULL;
        siz = 0;
    }

    int getSize() {
        return siz;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int data) {
        Node* temp = new Node(data);
        temp->next = top;
        top = temp;
        siz++;
    }

    void pop() {
        if (top == NULL) return;
        Node* temp = top;
        top = top->next;
        delete temp;
        siz--;
    }

    int getTop() {
        return (top == NULL) ? -1 : top->data;
    }
};