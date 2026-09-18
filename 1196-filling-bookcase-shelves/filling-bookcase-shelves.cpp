class Solution {
public:
    int solve(int i, int remW, int currentMaxH, vector<vector<int>>& books, int shelfWidth, vector<vector<int>>& dp) {
        if (i >= books.size()) return currentMaxH;
        if (dp[i][remW] != -1) return dp[i][remW];

        int bookW = books[i][0];
        int bookH = books[i][1];
        int keep = INT_MAX;
        if (bookW <= remW) {
            keep = solve(i + 1, remW - bookW, max(currentMaxH, bookH), books, shelfWidth, dp);
        }

        int skip = currentMaxH + solve(i + 1, shelfWidth - bookW, bookH, books, shelfWidth, dp);

        return dp[i][remW] = min(keep, skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));
        
        return solve(0, shelfWidth, 0, books, shelfWidth, dp);
    }
};