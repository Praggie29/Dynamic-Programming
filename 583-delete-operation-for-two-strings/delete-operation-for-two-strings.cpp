class Solution {
public:
    int f ( int i , int j , string &word1, string &word2 , vector<vector<int>>&dp ) {
        int n = word1.size();
        int m = word2.size();
        if ( i == n && j == m ) return 0;
        if ( i == n ) return m - j ;
        if ( j == m ) return n - i;
        if ( dp[i][j] != -1 ) return dp[i][j];
        int  b , c ;
        if ( word1[i] == word2[j] ) {
           return dp[i][j] = f ( i + 1 , j + 1 , word1 , word2 , dp );
        }
        b = 1 + f ( i + 1 , j , word1 , word2 , dp );
        c = 1 + f ( i , j + 1 , word1 , word2 , dp );
        return dp[i][j] = min ( b , c);
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f ( 0 , 0 , word1 , word2 , dp );
    }
};