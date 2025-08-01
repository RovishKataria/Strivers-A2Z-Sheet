// https://www.naukri.com/code360/problems/find-median-from-data-stream_6212830
// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
// https://leetcode.com/problems/find-median-from-data-stream/description/

// Implement class for MedianFinder.
class MedianFinder{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
public:
	MedianFinder(){
	};
	// Function to add the integer ?num? to the data structure.
	void addNum(int num){
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Ensure maxHeap is always equal to or 1 larger than minHeap
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
	}
	// Funtion that returns the median of all elements so far.
	double findMedian(){
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top(); // maxHeap always has the extra element if odd
	}
	
};