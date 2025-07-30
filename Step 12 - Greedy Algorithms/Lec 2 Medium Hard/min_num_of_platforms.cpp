// https://www.naukri.com/code360/problems/minimum-number-of-platforms_799400
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// https://www.youtube.com/watch?v=AsGzwR_FWok

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 0, j = 0, cnt = 0, max_platform = 0;

    while (i < n) {
        if (at[i] <= dt[j]) {
            cnt++;
            i++;
        } else {
            cnt--;
            j++;
        }
        max_platform = max(max_platform, cnt);
    }
    return max_platform;
}