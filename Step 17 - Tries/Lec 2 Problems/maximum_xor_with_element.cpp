// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
// https://www.youtube.com/watch?v=Q8LhG9Pi5KM
// Offline queries

#include <bits/stdc++.h>
struct Node {
	Node* links[2];
	bool containsKey(int bit) {
		return (links[bit] != NULL);
	}

	Node* get(int bit) {
		return links[bit];
	}

	void put(int bit, Node* node) {
		links[bit] = node;
	}
};

class Trie{
	private:
		Node* root;
	public:
		Trie() {
			root = new Node();
		}

		void insert(int num) {
			Node* node = root;
			for (int i=31; i>=0; i--) {
				int bit = (num >> i) & 1;
				if (!node->containsKey(bit)) {
					node->put(bit, new Node());
				}
				node = node->get(bit);
			}
		}
        
		int getMax(int num) {
			Node* node = root;
			int maxNum = 0;
			for (int i=31; i>=0; i--) {
				int bit = (num >> i) & 1;
				if (node->containsKey(1 - bit)) {
					maxNum = maxNum | (1 << i);
					node = node->get(1 - bit);
				}
				else node = node->get(bit);
			}
			return maxNum;
		}
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(), arr.end());
	vector<pair<int, pair<int, int>>> offlineQueue;
	int qSize = queries.size();
	for (int i=0; i<qSize; i++) {
		offlineQueue.push_back({queries[i][1], {queries[i][0], i}});
	}
	// TC = O(Q * logQ)
	sort(offlineQueue.begin(), offlineQueue.end());
	vector<int> ans(queries.size(), 0);
	int arrInd = 0;
	int arrSize = arr.size();
	Trie trie;
	// TC = O(Q * 32 + N * 32)
	for (int i=0; i<qSize; i++) {
		int ai = offlineQueue[i].first;
		int xi = offlineQueue[i].second.first;
		int qInd = offlineQueue[i].second.second;
		
		while (arrInd < arrSize && arr[arrInd] <= ai) {
			trie.insert(arr[arrInd]);
			arrInd++;
		}
		if (arrInd == 0) ans[qInd] = -1;
		else ans[qInd] = trie.getMax(xi);
	}
	return ans;
}
