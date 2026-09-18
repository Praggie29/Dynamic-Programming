class Solution {
public:
    int f(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>>& dp) {
        if (i == n || j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(i + 1, j + 1, n, m, s1, s2, dp);
        }
        return dp[i][j] = max(f(i + 1, j, n, m, s1, s2, dp), 
                              f(i, j + 1, n, m, s1, s2, dp));
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        f(0, 0, n, m, str1, str2, dp);

        
        for (int i = 0; i <= n; i++) dp[i][m] = 0;
        for (int j = 0; j <= m; j++) dp[n][j] = 0;

        int i = 0, j = 0;
        string ans = "";

        while (i < n && j < m) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                ans += str1[i];
                i++;
            } else {
                ans += str2[j];
                j++;
            }
        }

        
        while (i < n) {
            ans += str1[i];
            i++;
        }
        while (j < m) {
            ans += str2[j];
            j++;
        }

        return ans;
    }
};