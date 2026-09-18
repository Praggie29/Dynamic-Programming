class Solution {
public:
    int f ( int i , int prevIdx , string &s , int n , int k , vector<vector<int>>&dp ) {
        if ( i >= n ) return 0;
        if (dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];
        int pick = 0 , skip = 0;
        int currCharIdx = s[i] - 'a';
        if ( prevIdx == -1 || abs(prevIdx - currCharIdx) <= k ) {
            pick += 1 + f ( i + 1 , currCharIdx , s , n , k , dp );
        }
        skip += f ( i + 1 , prevIdx , s , n , k , dp );
        return dp[i][prevIdx+1] = max ( pick , skip );
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return f ( 0 , -1 , s , n , k , dp );
    }
};