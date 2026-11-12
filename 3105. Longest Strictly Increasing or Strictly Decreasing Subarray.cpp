#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        int n=nums.size();
        if(n==1)
            return ans;

        int i=0,j=1;
        while(i<n && j<n)
        {
            if(nums[j-1]>=nums[j])
            {
                ans=max(ans,j-i);
                i=j;
            }
            j++;
        }
        ans=max(ans,j-i);
        i=0;j=1;
        while(i<n && j<n)
        {
            if(nums[j-1]<=nums[j])
            {
                ans=max(ans,j-i);
                i=j;
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};