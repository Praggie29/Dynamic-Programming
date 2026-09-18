class Solution {
public:
    int bs ( vector<vector<int>>& events , int endEvent ) {
        int n = events.size();
        int l = 0;
        int r = n - 1;
        int res = n;
        while ( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if ( events[mid][0] > endEvent ) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
    int f ( int i , vector<vector<int>>& events , int chances , vector<vector<int>>& dp ) {
        if ( chances == 2 || i >= events.size() ) return 0;
        if ( dp[i][chances] != -1 ) return dp[i][chances];
        int take = 0 , skip = 0;
        int nextValidIndex = bs ( events , events[i][1] );
        take = events[i][2] + f ( nextValidIndex , events , chances+1 , dp );
        skip += f ( i + 1 , events , chances , dp );
        return dp[i][chances] = max ( take , skip );
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return f ( 0 , events , 0 , dp );
    }
};