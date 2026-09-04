#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<pair<int,int>> dp(n);

        int mx = nums[0];
        int mn = nums[n - 1];

        for (int i = 0, j = n - 1; i < n; i++, j--) {

            mx = max(mx, nums[i]);
            dp[i].first = mx;

            mn = min(mn, nums[j]);
            dp[j].second = mn;
        }

        for (int i = 0; i < n; i++) {

            int mx = dp[i].first;
            int mn = dp[i].second;

            if (mx - mn <= k)
                return i;
        }

        return -1;
    }
};
