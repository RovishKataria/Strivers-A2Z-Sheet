// https://www.naukri.com/code360/problems/lfucache_3114758
// https://www.naukri.com/code360/problems/lfu-cache_8381892
// https://www.geeksforgeeks.org/problems/lfu-cache-1665050355/1
// https://leetcode.com/problems/lfu-cache/description/
// https://www.youtube.com/watch?v=0PSB9y8ehbk
// https://www.youtube.com/watch?v=mzqHlAW7jeE

#include <bits/stdc++.h> 
struct Node {
    int key, value, cnt;
    Node *prev;
    Node *next;

    Node(int k, int v) {
        key = k;
        value = v;
        cnt = 1;
    }
};

struct List {
    int size;
    Node *head;
    Node *tail;

    List() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *del_node) {
        Node *delprev = del_node->prev;
        Node *delnext = del_node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
    int maxSizeCache, minFreq, curSize;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;

public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node *node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }
        
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key) {
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (maxSizeCache == 0) return;
        // key already exists in map, update value and freq
        if (keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        } else {
            if (curSize == maxSizeCache) {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            // new value to be added who is not there priviously
            minFreq = 1;
            List *list_freq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
                list_freq = freqListMap[minFreq];
            
            Node *node = new Node(key, value);
            list_freq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = list_freq;
        }
    }
};
