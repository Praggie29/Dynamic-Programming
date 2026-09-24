class Solution {
public:
    bool check ( int num , int i ) {
        int temp = num;
        int sum = 0;
        while (temp) {
           int rem = temp % 10;
           sum += rem;
           temp /= 10;
        }
        return sum == i;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( check(nums[i],i) == true ) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};