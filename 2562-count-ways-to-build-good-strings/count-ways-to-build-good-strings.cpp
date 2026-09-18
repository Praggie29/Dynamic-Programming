class Solution {
public:
    int M = 1e9 + 7;
    int f ( int len , int low, int high, int zero, int one , vector<int>&dp ) {
        if ( len > high ) return 0;
        if ( dp[len] != -1 ) return dp[len];
        int cnt = (len >= low && len <= high) ? 1 : 0;
        cnt = (cnt + f(len + zero, low, high, zero, one, dp)) % M;
        cnt = (cnt + f(len + one, low, high, zero, one, dp)) % M;
        return dp[len] = cnt;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return f(0, low, high, zero, one, dp);
    }
};