// https://www.geeksforgeeks.org/problems/graph-and-vertices/1
// https://www.youtube.com/watch?v=M3_pLsDdeuU

// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // no. of possible edges = (n*(n-1))/2
        // no. of undirected graphs = 2**(no. of edges)
        long long int power = (long long int)n * (n - 1) / 2;
        return 1LL << power; // Using bitwise shift operator
    }
};