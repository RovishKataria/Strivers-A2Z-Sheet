// https://www.naukri.com/code360/problems/candies_893290
// https://leetcode.com/problems/candy/description/
// https://www.youtube.com/watch?v=IIqVFvKE6RY

// brute
int requiredCandies(vector < int > &ratings) {
    int n = ratings.size();
    vector<int> left(n), right(n);
    left[0] = 1; right[n-1] = 1;

    // left
    for (int i=1; i<n; i++) {
        if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
        else left[i] = 1;
    }
    // right
    for (int i=n-2; i>=0; i--) {
        if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
        else right[i] = 1;
    }
    int sum = 0;
    for (int i=0; i<n; i++) sum += max(left[i], right[i]);
    return sum;
}

// optimal
int requiredCandies(vector < int > &ratings) {
    int n = ratings.size();
    int sum = 1, i = 1;
    while (i < n) {
        if (ratings[i] == ratings[i-1]) {
            sum += 1; i++; continue;
        }
        // inc slope
        int peak = 1;
        while (i < n && ratings[i] > ratings[i-1]) {
            peak++; sum += peak; i++;
        }
        // dec slope
        int down = 1;
        while (i < n && ratings[i] < ratings[i-1]) {
            sum += down; down++; i++;
        }
        if (down > peak) sum += (down - peak);
    }
    return sum;
}

