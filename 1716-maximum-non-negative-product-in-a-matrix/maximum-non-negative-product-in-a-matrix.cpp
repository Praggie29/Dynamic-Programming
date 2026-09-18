class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;

    pair<ll, ll> f(int i, int j, int n, int m, vector<vector<pair<ll,ll>>>& dp, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1) { 
            return { grid[i][j], grid[i][j] }; 
        } 
        if (dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX)) { 
            return dp[i][j]; 
        } 

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;
        if (i + 1 < n) {
            auto [downMax, downMin] = f(i + 1, j, n, m, dp, grid);
            maxVal = max({ maxVal, grid[i][j] * downMax, grid[i][j] * downMin });
            minVal = min({ minVal, grid[i][j] * downMax, grid[i][j] * downMin });
        }
        if (j + 1 < m) {
            auto [leftMax, leftMin] = f(i, j + 1, n, m, dp, grid);
            maxVal = max({ maxVal, grid[i][j] * leftMax, grid[i][j] * leftMin });
            minVal = min({ minVal, grid[i][j] * leftMax, grid[i][j] * leftMin });
        }
        return dp[i][j] = { maxVal, minVal }; 
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(m, {LLONG_MIN, LLONG_MAX}));
        
        auto [maxProd, minProd] = f(0, 0, n, m, dp, grid);
        
        return maxProd < 0 ? -1 : maxProd % M; 
    }
};