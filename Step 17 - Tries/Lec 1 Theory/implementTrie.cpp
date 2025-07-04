// https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
// https://www.youtube.com/watch?v=dBGUmUQhjaM

// User function template for C++
struct Node {
    Node* lists[26];
    bool flag;
    
    bool containsKey(char ch) {
        return (lists[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node) {
        lists[ch - 'a'] = node;
    }
    
    Node* get(char ch) {
        return lists[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    
    bool getEnd() {
        return flag;
    }
};
class Trie {
    private:
        Node* root;
  public:

    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string &word) {
        // search word in the Trie
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* node = root;
        for (int i=0; i<word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
