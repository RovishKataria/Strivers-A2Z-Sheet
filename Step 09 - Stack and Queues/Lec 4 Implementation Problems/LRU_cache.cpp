// https://www.naukri.com/code360/problems/lru-cache-implementation_670276
// https://www.naukri.com/code360/problems/lru-cache_6212844
// https://www.naukri.com/code360/problems/lru-cache-implementation_981239
// https://www.geeksforgeeks.org/problems/lru-cache/1
// https://leetcode.com/problems/lru-cache/description/
// https://www.youtube.com/watch?v=z9bJUPxzFOw

#include<bits/stdc++.h>
class Node {
public:
    int key, data;
    Node *prev;
    Node *next;

    Node(int k, int v) {
        key = k;
        data = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int cap = 0;
    Node *head, *tail;
    unordered_map<int, Node*> umpp;

    void deleteNode(Node* node) {
        if (!node || !node->prev || !node->next) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insertAfterHead(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        umpp.clear();
        
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        if (umpp.find(key) == umpp.end()) return -1;
        Node* node = umpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->data;
    }

    void put(int key, int value) {
        if (umpp.find(key) != umpp.end()) {
            Node* node = umpp[key];
            deleteNode(node);
            node->data = value;
            insertAfterHead(node);
        } else {
            if (umpp.size() == cap) {
                Node* node = tail->prev;
                umpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node = new Node(key, value);
            umpp[key] = node;
            insertAfterHead(node);
        }
    }
};
