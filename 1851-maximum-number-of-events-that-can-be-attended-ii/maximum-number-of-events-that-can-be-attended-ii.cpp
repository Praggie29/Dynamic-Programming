class Solution {
public:
    int bs (int endTimeValue , vector<vector<int>>& events) {
       int n = events.size();
       int l = 0 , r = n - 1;
       int res = n ;
       while ( l <= r ) {
          int mid = l + (r - l) / 2;
          if ( events[mid][0] > endTimeValue ) {
              res = mid;
              r = mid - 1;
          }
          else {
             l = mid + 1;
          }
       }
       return res;
   }
   int f ( int i , vector<vector<int>>& events, int count , int k , vector<vector<int>>&dp ) {
        int n = events.size();
        if ( i >= n || count == k ) return 0;
        if ( dp[i][count] != -1 ) return dp[i][count];
        int take = 0 , skip = 0;
        int nextIndex = bs ( events[i][1] ,events );
        take = events[i][2] + f ( nextIndex , events , count + 1 , k , dp );
        skip += f ( i + 1 , events , count , k , dp );
        return dp[i][count] = max ( take , skip );
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f ( 0 , events , 0 ,  k , dp );
    }
};