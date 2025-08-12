// https://www.naukri.com/code360/problems/-divide-two-integers_1112617
// https://www.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1
// https://leetcode.com/problems/divide-two-integers/description/
// https://www.youtube.com/watch?v=pBD4B1tzgVc

#include<bits/stdc++.h>
int divideTwoInteger(int dividend, int divisor) {
	if (dividend == divisor) return 1;
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	if (dividend == INT_MIN && divisor == 1) return INT_MIN;

	bool sign = true;
	if (dividend >= 0 && divisor < 0) sign = false;
	if (dividend <= 0 && divisor > 0) sign = false;
	
	long long n = abs((long long)dividend);
	long long d = abs((long long)divisor);
	long long quotient = 0;
	
	while (n >= d) {
		int cnt = 0;
		while (n >= (d << (cnt + 1))) cnt++;
		quotient += 1<<cnt;
		n = n - (d << cnt);
	}
	if (quotient >= (1LL << 31) && sign) return INT_MAX;
	if (quotient >= (1LL << 31) && !sign) return INT_MIN;
	return sign ? quotient : -quotient;
}
