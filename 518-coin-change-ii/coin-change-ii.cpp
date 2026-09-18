class Solution {
public:
    int f ( int i , vector<int>&coins , int n , int target , vector<vector<int>>&dp ) {
        if ( i == n ) return target == 0 ? 1 : 0;
        if ( target == 0 ) return 1;
        if ( dp[i][target] != -1 ) return dp[i][target];
        int add = 0;
        if ( target - coins[i] >= 0 ) add = add + f ( i  , coins , n , target - coins[i] , dp );
        int skip = f ( i + 1 , coins , n , target , dp );
        return dp[i][target] = add + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f ( 0 , coins , n , amount , dp );
        return ans == -1 ? 0 : ans;
    }
};