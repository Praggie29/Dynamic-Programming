class Solution {
public:
    int f(int i, int choice, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        int n = nums1.size();
        if (i >= n) return 0;
        if (dp[i][choice] != -1) return dp[i][choice];

        int prevVal = (choice == 0) ? nums1[i - 1] : nums2[i - 1];
        int maxLen = 0;
        if (nums1[i] >= prevVal) {
            maxLen = max(maxLen, 1 + f(i + 1, 0, nums1, nums2, dp));
        }
        if (nums2[i] >= prevVal) {
            maxLen = max(maxLen, 1 + f(i + 1, 1, nums1, nums2, dp));
        }

        return dp[i][choice] = maxLen;
    }

    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int option1 = 1 + f(i + 1, 0, nums1, nums2, dp);
            int option2 = 1 + f(i + 1, 1, nums1, nums2, dp);
            ans = max({ans, option1, option2});
        }
        
        return ans;
    }
};