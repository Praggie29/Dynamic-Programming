class Solution {
public:
    int f(int i, vector<int>& arr, int difference, vector<int>& dp, unordered_map<int, int>& val_to_index) {
        if (i >= arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int LAS = 1;
        int target = arr[i] + difference;
        if (val_to_index.count(target)) {
            int j = val_to_index[target];
            LAS = 1 + f(j, arr, difference, dp, val_to_index);
        }

        return dp[i] = LAS;
    }

    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> dp(n, -1);
        unordered_map<int, int> val_to_index;

        int maxLen = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxLen = max(maxLen, f(i, arr, difference, dp, val_to_index));
            val_to_index[arr[i]] = i; 
        }

        return maxLen;
    }
};