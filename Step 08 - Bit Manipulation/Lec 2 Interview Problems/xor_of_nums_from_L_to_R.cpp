// https://www.naukri.com/code360/problems/l-to-r-xor_8160412
// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1
// https://www.youtube.com/watch?v=WqGb7159h7Q

int func(int n) {
    if (n%4 == 1) return 1;
    if (n%4 == 2) return n+1;
    if (n%4 == 3) return 0;
    return n;
}
int findXOR(int L, int R) {
    return func(L-1) ^ func(R);
}