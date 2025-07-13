// https://www.geeksforgeeks.org/problems/word-ladder-ii/1
// https://leetcode.com/problems/word-ladder-ii/description/
// below sol will not work on leetcode but good for interviews
// https://www.youtube.com/watch?v=DREutrv2XD0
// Optimised
// https://www.youtube.com/watch?v=AD4SFl7tu7I

// below sol will not work on leetcode but good for interviews
class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            
            // Erase all words that has been used in previous level
            if (vec.size() > level) {
                level++;
                for (auto it:usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string word = vec.back();
            if (word == endWord) {
                // first sequence reaching end
                if (!ans.size()) {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            for (int i=0; i<word.size(); i++) {
                char original = word[i];
                for (char ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if (st.count(word) > 0) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};