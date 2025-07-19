// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1
// https://www.youtube.com/watch?v=aBxjDBC4M1U

/*Complete the functions below*/
int find(int par[], int x) {
    if (par[x] == x) return x;
    return par[x] = find(par, par[x]);
}

void unionSet(int par[], int x, int z) {
    int ulp_u = find(par, x);
    int ulp_v = find(par, z);
    if (ulp_u == ulp_v) return;
    par[ulp_u] = ulp_v;
}