class Solution {
public:
    int f ( int i , int currSum , int n , vector<int>&nums , int target , vector<vector<int>>&dp ) {
        if ( i == n ) {
            if ( currSum == target ) return 1;
            return 0;
        }
        if ( dp[i][currSum + 1000 ] != -1 ) return dp[i][currSum + 1000 ];
        int addPlus =  f ( i + 1 , currSum + nums[i] , n , nums , target , dp );
        int addMinus = f ( i + 1 , currSum - nums[i] , n , nums , target , dp );
        return dp[i][currSum + 1000 ] = addPlus + addMinus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return f ( 0 , 0 , n , nums , target , dp );
    }
};