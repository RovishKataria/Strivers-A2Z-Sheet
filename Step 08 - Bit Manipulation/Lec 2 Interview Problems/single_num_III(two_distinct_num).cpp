// https://www.naukri.com/code360/problems/two-non-repeating-elements_704683
// https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
// https://leetcode.com/problems/single-number-iii/description/
// https://www.youtube.com/watch?v=UA5JnV1J2sI

#include <bits/stdc++.h> 
void twoNonRepeatingElements(int arr[], int n) {
   long long xorr = 0;
   for (int i=0; i<n; i++) xorr ^= arr[i];
   int rightmost = (xorr & (xorr-1)) ^ xorr;
   int b1 = 0, b2 = 0;
   for (int i=0; i<n; i++) {
      if (rightmost & arr[i]) b1 ^=  arr[i];
      else b2 ^= arr[i];
   }
   if (b1 < b2) cout<<b1<<" "<<b2;
   else cout<<b2<<" "<<b1;
}
