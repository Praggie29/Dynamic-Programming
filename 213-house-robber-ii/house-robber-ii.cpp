class Solution {
public:
    int f ( int i , vector<int>&nums , vector<int>&dp ) {
        if ( i >= nums.size() ) return 0;
        if ( i == nums.size() - 1 ) return nums[nums.size()-1];
        if ( dp[i] != -1 ) return dp[i];
        int pick = nums[i] + f ( i + 2 , nums , dp );
        int notPick = 0 + f ( i + 1 , nums , dp );
        return dp[i] = max ( pick , notPick );
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if ( n == 1 ) return nums[0];
        vector<int>nums1;
        vector<int>nums2;
        for ( int i = 0 ; i < n - 1 ; i ++ ) nums1.push_back(nums[i]);
        for ( int i = 1 ; i < n ; i ++ ) nums2.push_back(nums[i]);
        vector<int>dp1(n-1,-1);
        vector<int>dp2(n-1,-1);
        int first = f ( 0 , nums1 , dp1 );
        int second = f ( 0 , nums2 , dp2 );
        return max ( first , second );
    }
};