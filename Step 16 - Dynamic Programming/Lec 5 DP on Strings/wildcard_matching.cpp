// https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650
// https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1
// https://leetcode.com/problems/wildcard-matching/description/
// https://www.youtube.com/watch?v=ZmlQ3vgAOMo

// memoization
#include<bits/stdc++.h>
bool f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
   if (i<0 && j<0) return true;
   if (i<0 && j>=0) return false;
   if (j<0 && i>=0) {
      for (int ind=0; ind<=i; ind++) {
         if (s1[ind] != '*') return false;
      }
      return true;
   }
   if (dp[i][j] != -1) return dp[i][j];

   if (s1[i] == s2[j] || s1[i] == '?')
      return dp[i][j] = f(i-1, j-1, s1, s2, dp);
   if (s1[i] == '*')
      return dp[i][j] = f(i-1, j, s1, s2, dp) | f(i, j-1, s1, s2, dp);
   
   return false;
}
bool wildcardMatching(string pattern, string text) {
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>> dp(n, vector<int> (m, -1));
   return f(n-1, m-1, pattern, text, dp);
}

// 0-based indexed
#include<bits/stdc++.h>
bool f(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
   if (i==0 && j==0) return true;
   if (i==0 && j>0) return false;
   if (j==0 && i>0) {
      for (int ind=1; ind<=i; ind++) {
         if (s1[ind-1] != '*') return false;
      }
      return true;
   }
   if (dp[i][j] != -1) return dp[i][j];

   if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
      return dp[i][j] = f(i-1, j-1, s1, s2, dp);
   if (s1[i-1] == '*')
      return dp[i][j] = f(i-1, j, s1, s2, dp) | f(i, j-1, s1, s2, dp);
   
   return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text) {
   int n = pattern.size();
   int m = text.size();
   vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
   return f(n, m, pattern, text, dp);
}

// tabulation
#include<bits/stdc++.h>
bool wildcardMatching(string s1, string s2) {
   int n = s1.size();
   int m = s2.size();
   
   vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
   dp[0][0] = true;
   for (int j=1; j<=m; j++) dp[0][j] = false;
   
   for (int i=1; i<=n; i++) {
      bool flag = true;
      for (int ind=1; ind<=i; ind++) {
         if (s1[ind-1] != '*') {
            flag = false;
            break;
         }
      }
      dp[i][0] = flag;
   }

   for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
         if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
            dp[i][j] = dp[i-1][j-1];
         else if (s1[i-1] == '*')
            dp[i][j] = dp[i-1][j] | dp[i][j-1];
         
         else dp[i][j] = false;
      }
   }

   return dp[n][m];
}

// optimized
#include<bits/stdc++.h>
bool wildcardMatching(string s1, string s2) {
   int n = s1.size();
   int m = s2.size();
   
   vector<bool> prev(m+1, false), curr(m+1, false);
   prev[0] = true;
   for (int j=1; j<=m; j++) prev[j] = false;
   
   for (int i=1; i<=n; i++) {
      bool flag = true;
      for (int ind=1; ind<=i; ind++) {
         if (s1[ind-1] != '*') {
            flag = false;
            break;
         }
      }
      // for every row, assigning the 0th column's value
      curr[0] = flag;

      for (int j=1; j<=m; j++) {
         if (s1[i-1] == s2[j-1] || s1[i-1] == '?')
            curr[j] = prev[j-1];
         else if (s1[i-1] == '*')
            curr[j] = prev[j] | curr[j-1];
         
         else curr[j] = false;
      }
      prev = curr;
   }

   return prev[m];
}
