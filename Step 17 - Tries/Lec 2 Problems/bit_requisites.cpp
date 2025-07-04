// https://www.geeksforgeeks.org/problems/bits-basic-operations/1
// https://www.youtube.com/watch?v=5iyuU4hQFrw

class Solution {
  public:
    int XOR(int n, int m) {
        return (n^m); 
    }

    int check(int a, int b) {
        return ((b >> (a-1)) & 1);
    }

        
    int setBit(int c, int d) {
        return (d|(1<<c));
    }
};