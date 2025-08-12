// https://www.naukri.com/code360/problems/number-of-flips_3125902
// https://www.geeksforgeeks.org/problems/bit-difference-1587115620/1
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// https://www.youtube.com/watch?v=OOdrmcfZXd8

#include <bits/stdc++.h> 
int numberOfFlips(int a, int b) {
    int ans = a ^ b;
    int cnt = 0;
    for (int i=0; i<31; i++) {
        if (ans & (1 << i)) cnt++;
    }
    return cnt;
}

// using hamming weight
#include <bits/stdc++.h> 
int numberOfFlips(int a, int b) {
    int ans = a ^ b;
    int cnt = 0;
    while (ans != 0) {
        ans = ans & (ans - 1);
        cnt++;
    }
    return cnt;
}