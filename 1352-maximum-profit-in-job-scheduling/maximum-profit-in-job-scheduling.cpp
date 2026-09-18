class Solution {
public:
   int bs (int endTimeValue , vector<pair<int, int>>& startTimeAndIndices) {
       int n = startTimeAndIndices.size();
       int l = 0 , r = n - 1;
       int res = n ;
       while ( l <= r ) {
          int mid = l + (r - l) / 2;
          if ( startTimeAndIndices[mid].first >= endTimeValue ) {
              res = mid;
              r = mid - 1;
          }
          else {
             l = mid + 1;
          }
       }
       return res;
   }
    int f ( int i , vector<pair<int, int>>& startTimeAndIndices, vector<int>& endTime, vector<int>& profit , vector<int>&dp ) {
        int n = endTime.size();
        if ( i >= n ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int take = 0 , skip = 0;
        int nextIndex = bs ( endTime[startTimeAndIndices[i].second] ,startTimeAndIndices );
        take = profit[startTimeAndIndices[i].second] + f ( nextIndex , startTimeAndIndices , endTime , profit , dp );
        skip += f ( i + 1 , startTimeAndIndices , endTime , profit , dp );
        return dp[i] = max ( take , skip );
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, int>>startTimeAndIndices;
        for ( int i = 0 ; i < n ; i ++ ) startTimeAndIndices.push_back({startTime[i],i});
        sort ( startTimeAndIndices.begin(),startTimeAndIndices.end());
        vector<int>dp(n,-1);
        return f ( 0 , startTimeAndIndices , endTime , profit , dp );
    }
};