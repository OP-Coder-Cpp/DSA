#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int mn = nums[0];
        int mx = nums[0];

        int mn_pos = 0;
        int mx_pos = 0;

        // Find min and max positions
        for (int i = 0; i < n; i++) {

            if (nums[i] < mn) {
                mn = nums[i];
                mn_pos = i;
            }

            if (nums[i] > mx) {
                mx = nums[i];
                mx_pos = i;
            }
        }

        int left = min(mn_pos, mx_pos);
        int right = max(mn_pos, mx_pos);

        
        int option1 = right + 1;

        
        int option2 = n - left;

        
        int option3 = (left + 1) + (n - right);

        return min({option1, option2, option3});
    }
};