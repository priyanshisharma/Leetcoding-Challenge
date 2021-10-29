/*
https://leetcode.com/problems/longest-common-subsequence/submissions/
*/

class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
      vector<vector<int>> arr(a.size() + 1, vector<int>(b.size() + 1));
      for (int i = 1; i <= a.size(); i++)
        for (int j = 1; j <= b.size(); j++)
          if (a[i - 1] == b[j - 1]) arr[i][j] = arr[i - 1][j - 1] + 1;
          else arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
      return arr[a.size()][b.size()];
    }
};
