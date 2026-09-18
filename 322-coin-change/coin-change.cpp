class Solution {
public:
    long long f ( int i , long long currSum , vector<int>&coins , int n , int target , vector<vector<int>>&dp ) {
        if ( i == n ) return currSum == target ? 0 : 1e9;
        if ( currSum > target ) return 1e9;
        if ( currSum == target ) return 0;
        if ( dp[i][currSum] != -1 ) return dp[i][currSum];
        long long add = 1e9;
        if (currSum + coins[i] <= target ) {
           add = 1 + f(i, currSum + coins[i], coins, n, target, dp);
        }
        long long skip = f ( i + 1 , currSum ,  coins , n , target , dp );
        return dp[i][currSum] = min ( add , skip );
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount + 1 ,-1));
        int ans =  f ( 0 , 0 ,  coins , n , amount , dp );
        return ans >= 1e9 ? -1 : ans;
    }
};