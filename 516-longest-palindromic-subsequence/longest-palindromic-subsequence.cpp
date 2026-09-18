class Solution {
public:
    int f ( int i , int j , int n , string &text1 , string &text2 , vector<vector<int>>&dp ) {
        if ( i == n || j == n ) return 0;
        if ( dp[i][j] != -1 ) return dp[i][j];
        int a = 0;
        if ( text1[i] == text2[j] ) {
            a = 1 + f ( i + 1 , j + 1 , n , text1 , text2 , dp );
        }
        int b  = 0 + max ( f ( i + 1 , j , n , text1 , text2 , dp ) , f ( i , j + 1 , n , text1 , text2 , dp ));
        return dp[i][j] = max ( a , b );
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = f ( 0 , 0 , n , s , s2 , dp );
        return ans;
    }
};