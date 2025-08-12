// https://www.naukri.com/code360/problems/swap-two-numbers_1112577
// https://www.geeksforgeeks.org/problems/swap-two-numbers3844/1
// https://www.youtube.com/watch?v=nttpF8kwgd4

void swapNumber(int &a, int &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}