class Solution {
public:
    int f ( int i , int buy , int transaction , vector<int>&prices , vector<vector<vector<int>>>&dp ) {
        if ( transaction == 0 ) return 0;
        if ( i == prices.size() ) return 0;
        if ( dp[i][buy][transaction] != -1 ) return dp[i][buy][transaction];
        int profit = 0;
        if (buy) {
           profit = max ( ( -prices[i] + f ( i + 1 , 0 , transaction , prices , dp ))  , ( 0 + f ( i + 1 , 1 , transaction , prices , dp )));
        }
        else{
           profit = max ( ( prices[i] + f ( i + 1 , 1 , transaction - 1, prices , dp )) , ( 0 + f ( i + 1 , 0 , transaction , prices , dp )));
        }
        return dp[i][buy][transaction] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f ( 0 , 1 , k , prices , dp );
    }
};