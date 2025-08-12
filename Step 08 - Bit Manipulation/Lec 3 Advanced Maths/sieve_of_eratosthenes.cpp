// https://www.naukri.com/code360/problems/find-prime-numbers_839723
// https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1
// https://leetcode.com/problems/count-primes/description/
// https://www.youtube.com/watch?v=g5Fuxn_AvSk

vector<int> primeNumbersTillN(int n) {
    vector<int> prime(n+1, 1);
    for (int i=2; i*i<=n; i++) {
        if (prime[i] == 1) {
            for (int j=i*i; j<=n; j+=i) {
                prime[j] = 0;
            }
        }
    }
    vector<int> ans;
    for (int i=2; i<=n; i++) {
        if (prime[i] == 1) ans.push_back(i);
    }
    return ans;
}