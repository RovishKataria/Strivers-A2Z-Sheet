// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1
// https://www.youtube.com/watch?v=glKWkmKFlMw

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {
        vector<int> spf(n+1);
        sieve(spf);
        for (int i=2; i<=n; i++) spf[i] = i;
        for (int i=2; i*i<=n; i++) {
            if (spf[i] == i) {
                for (int j=i*i; j<=n; j+=i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        vector<int> ans;
        while (n != 1) {
            ans.push_back(spf[n]);
            n = n/spf[n];
        }
        return ans;
    }
};