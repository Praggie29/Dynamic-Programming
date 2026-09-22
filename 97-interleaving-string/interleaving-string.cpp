class Solution {
public:
    bool f ( int i , int j , string &s1 , string &s2 , string &s3 , vector<vector<int>>&dp ) {
        int n = s1.size();
        int m = s2.size();
        if ( i == n && j == m ) return true;
        if ( dp[i][j] != -1 ) return dp[i][j];
        bool ans = false;
        if ( i < n && s1[i] == s3[i+j] ) ans = ans || f ( i + 1 , j , s1 , s2 , s3 , dp );
        if ( j < m && s2[j] == s3[i+j] ) ans = ans || f ( i , j + 1 , s1 , s2 , s3 , dp );
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if ( n + m != k ) return false;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f ( 0 , 0 , s1 , s2 , s3 , dp );
    }
};