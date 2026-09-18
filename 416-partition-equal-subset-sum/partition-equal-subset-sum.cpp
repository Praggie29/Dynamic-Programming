class Solution {
public:
    bool f ( int i , vector<int>&nums , int target , vector<vector<int>>&dp ) {
        if ( target == 0 ) return true;
        if ( i == nums.size() - 1 ) return nums[i] == target;
        if ( dp[i][target] != -1 ) return dp[i][target];
        bool notTake = f ( i + 1 , nums , target , dp );
        bool take = false;
        if ( nums[i] <= target ) {
            take = f ( i + 1 , nums , target - nums[i] , dp );
        }
        return dp[i][target]  = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for ( int i = 0 ; i < n ; i ++ ) sum += nums[i];
        if ( sum % 2 != 0 ) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f ( 0 , nums , target , dp );
    }
};