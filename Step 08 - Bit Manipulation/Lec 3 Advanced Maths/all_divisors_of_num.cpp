// https://www.naukri.com/code360/problems/print-all-divisors-of-a-number_1164188
// https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
// https://www.youtube.com/watch?v=Ae_Ag_saG9s

int* printDivisors(int n, int &size){
    vector<int> ans;
    for (int i=1; i*i<=n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            if (n/i != i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());

    size = ans.size(); // set the size
    int *res = new int[size]; // allocate memory
    for (int i = 0; i < size; i++) res[i] = ans[i];
    return res; // caller must delete[] res after use
}
