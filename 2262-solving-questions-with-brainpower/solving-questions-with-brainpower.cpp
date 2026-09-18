class Solution {
public:
    long long f ( int i , vector<vector<int>>& questions , int n , vector<long long>&dp ) {
        if ( i >= n ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        long long take = questions[i][0] + f(i + questions[i][1] + 1, questions, n, dp);
        long long skip = f ( i + 1 , questions , n , dp );
        return dp[i] = max ( take , skip );
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return f ( 0 , questions , n , dp );
    }
};