class Solution {
public:
    int f ( int i , vector<int>&nums , vector<int>&dp ) {
        if ( i == nums.size() - 1 ) return nums[nums.size()-1];
        if ( i >= nums.size() ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        return dp[i] = max(nums[i],nums[i] + f ( i + 1 , nums , dp ));
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int maxi = INT_MIN;
        for ( int i = 0 ; i < n ; i ++ ) {
            maxi = max ( maxi , f ( i , nums , dp ));
        }
        return maxi;
    }
};