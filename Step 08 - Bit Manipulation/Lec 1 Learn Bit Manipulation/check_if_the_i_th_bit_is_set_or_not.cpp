// https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446
// https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1
// https://www.youtube.com/watch?v=nttpF8kwgd4

bool isKthBitSet(int n, int k) {
    return (n & (1 << k-1)) == 0 ? false : true;
}