// https://www.naukri.com/code360/problems/maximum-points-from-cards_8391016
// https://www.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// https://www.youtube.com/watch?v=pBWCOCS636U

int maxPoints(vector<int>&arr , int k){
    int lsum = 0, rsum = 0, maxsum = 0;
    for (int i=0; i<k; i++) lsum += arr[i];
    maxsum = lsum;
    int rind = arr.size()-1;
    for (int i=k-1; i>=0; i--) {
        lsum -= arr[i];
        rsum += arr[rind];
        rind--;
        maxsum = max(maxsum, lsum + rsum);
    }
    return maxsum;
}