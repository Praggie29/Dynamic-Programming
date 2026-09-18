class Solution {
public:
    int f ( int i , vector<int>&nums , int target , vector<int>&dp ) {
        if ( i == nums.size() - 1 ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int maxJumps = INT_MIN;
        for ( int j = i + 1 ; j < nums.size() ; j ++ ) {
            if ( abs(nums[j] - nums[i]) <= target ) {
                maxJumps = max (maxJumps , 1 + f ( j , nums , target , dp ));
            }
        }
        return dp[i] = maxJumps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = f ( 0 , nums , target , dp );
        return ans <= -1 ? -1 : ans;
    }
};