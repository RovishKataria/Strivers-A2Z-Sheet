// https://www.naukri.com/code360/problems/trapping-rain-water_630519
// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// https://leetcode.com/problems/trapping-rain-water/description/
// https://www.youtube.com/watch?v=1_5VuquLbXg

long long getTrappedWater(long long* arr, int n) {
    long long lmax = 0, rmax = 0, total = 0;
    long long l = 0, r = n-1;
    while (l < r) {
        if (arr[l] <= arr[r]) {
            if (lmax > arr[l]) total += lmax - arr[l];
            else lmax = arr[l];
            l++;
        } else {
            if (rmax > arr[r]) total += rmax - arr[r];
            else rmax = arr[r];
            r--;
        }
    }
    return total;
}