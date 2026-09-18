class Solution {
public:
    int f ( int i , int buy , int fee , vector<int>& prices , vector<vector<int>>&dp ) {
        if ( i == prices.size() ) return 0;
        if ( dp[i][buy] != -1 ) return dp[i][buy];
        int profit = 0;
        if (buy) {
           profit = max ( ( -prices[i] + f ( i + 1 , 0 , fee , prices , dp ))  , ( 0 + f ( i + 1 , 1  , fee , prices , dp )));
        }
        else{
           profit = max ( ( prices[i] - fee + f ( i + 1 , 1 , fee , prices , dp )) , ( 0 + f ( i + 1 , 0 , fee , prices , dp )));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f ( 0 , 1 , fee , prices , dp );
    }
};