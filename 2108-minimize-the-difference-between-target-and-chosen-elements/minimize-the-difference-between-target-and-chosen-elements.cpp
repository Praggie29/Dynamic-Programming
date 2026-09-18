class Solution {
public:
    int f ( int i , int n , int m , vector<vector<int>>& mat, int sum , int target , vector<vector<int>>& dp) {
        if ( i == n ) return abs ( sum - target );
        if ( dp[i][sum] != -1 ) return dp[i][sum];
        int mini = INT_MAX;
        for ( int j = 0 ; j < m ; j ++ ) {
            mini = min ( mini , f ( i + 1 , n , m , mat , sum + mat[i][j] , target , dp ));
        }
        return dp[i][sum] = mini;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(5000,-1));
        return f ( 0 , n , m , mat , 0 , target , dp );
    }
};