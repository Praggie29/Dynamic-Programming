class Solution {
public:
    int solve(int i, int prev_idx, vector<int>& nums, vector<vector<int>>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];
        int notTake = solve(i + 1, prev_idx, nums, dp);
        int take = 0;
        if (prev_idx == -1 || nums[i] % nums[prev_idx] == 0) {
            take = 1 + solve(i + 1, i, nums, dp);
        }
        
        return dp[i][prev_idx + 1] = max(take, notTake);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<int> result;
        int prev_idx = -1;
        
        for (int i = 0; i < n; i++) {
            if ((prev_idx == -1 || nums[i] % nums[prev_idx] == 0) &&
                1 + solve(i + 1, i, nums, dp) == solve(i, prev_idx, nums, dp)) {
                
                result.push_back(nums[i]);
                prev_idx = i;
            }
        }
        
        return result;
    }
};