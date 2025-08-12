// https://www.naukri.com/code360/problems/find-x-raised-to-power-n-_626560
// https://leetcode.com/problems/powx-n/description/
// https://www.youtube.com/watch?v=hFWckDXE-K8

double myPow(double x, int n) {
    double ans = 1.0;
    long long power = n; // if n == INT_MIN
    if (power < 0) power = -power;
    while (power > 0) {
        if (power % 2 == 1) { // odd power
            ans *= x;
            power--;
        } else { // even power
            power /= 2;
            x *= x;
        }
    }
    if (n < 0) ans = 1.0/ans; // -ve power
    return ans;
}