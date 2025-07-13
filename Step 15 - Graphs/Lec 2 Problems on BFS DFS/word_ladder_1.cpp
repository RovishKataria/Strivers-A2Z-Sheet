// https://www.geeksforgeeks.org/problems/word-ladder/1
// https://leetcode.com/problems/word-ladder/description/
// https://www.youtube.com/watch?v=tRPda0rcf8E

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        // TC = N * word.length * 26
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == targetWord) return steps;
            
            // TC = word.length * 26
            for (int i=0; i<word.size(); i++) {
                char original = word[i];
                for (char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    // it exists
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};