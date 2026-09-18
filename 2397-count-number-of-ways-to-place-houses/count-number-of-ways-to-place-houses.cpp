class Solution {
    int MOD = 1e9 + 7;

    long long solve(int n, vector<long long>& memo) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        if (memo[n] != -1) return memo[n];

        memo[n] = (solve(n - 1, memo) + solve(n - 2, memo)) % MOD;
        return memo[n];
    }

public:
    int countHousePlacements(int n) {
        vector<long long> memo(n + 1, -1);
        long long ways_one_side = solve(n, memo);
        
        return (ways_one_side * ways_one_side) % MOD;
    }
};