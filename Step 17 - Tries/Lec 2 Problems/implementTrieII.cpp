// https://www.naukri.com/code360/problems/implement-trie_1387095
// https://www.youtube.com/watch?v=K5pcpkEMCN0

#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void incPrefix() {
        cntPrefix++;
    }

    void decPrefix() {
        cntPrefix--;
    }

    void incEnd() {
        cntEndWith++;
    }

    void decEnd() {
        cntEndWith--;
    }

    int getEnd() {
        return cntEndWith;
    }
    int getPrefix() {
        return cntPrefix;
    }
};

class Trie{
    private:
        Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incPrefix();
        }
        node->incEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    // Assuming that word present
    void erase(string &word){
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return;
            }
            node = node->get(word[i]);
            node->decPrefix();
        }
        node->decEnd();
    }
};
