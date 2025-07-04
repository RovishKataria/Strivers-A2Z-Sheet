// https://www.naukri.com/code360/problems/complete-string_2687860
// https://www.youtube.com/watch?v=AWnBa91lThI

#include <bits/stdc++.h> 

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node = root;
            for (int i=0; i<word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }

        bool checkIfPrefixExists(string word) {
            Node* node = root;
            for(int i=0; i<word.size(); i++) {
                if (!node->containsKey(word[i])) {
                    return false;
                }
                node = node->get(word[i]);
                if (node->isEnd() == false) {
                    return false;
                }
            }
            return true;
        }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for (auto &it:a) {
        trie.insert(it);
    }
    string longest = "";
    for (auto &it:a) {
        if (trie.checkIfPrefixExists(it)) {
            if (longest.empty() || it.size() > longest.size()) {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest) {
                longest = it;
            }
        }
    }
    if (longest == "") return "None";
    return longest;
}
