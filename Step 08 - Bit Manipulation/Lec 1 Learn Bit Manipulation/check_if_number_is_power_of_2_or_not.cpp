// https://www.naukri.com/code360/problems/power-of-two_893061
// https://www.geeksforgeeks.org/problems/power-of-2-1587115620/1
// https://leetcode.com/problems/power-of-two/description/
// https://www.youtube.com/watch?v=nttpF8kwgd4

bool isPowerOfTwo(int n) {
    return (n & (n-1)) == 0 ? true : false;
}