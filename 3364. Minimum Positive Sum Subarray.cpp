#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        prefix[1]=nums[0];
        for(int i=2;i<=n;i++)
            prefix[i]+=prefix[i-1]+nums[i-1];

        int ans=INT_MAX;
        for(int w=l;w<=r;w++)
        {
            int left=1,right=left+w-1;
            for(;right<=n;right++)
            {
                int temp=prefix[right]-prefix[left-1];
                if(temp>0)
                    ans=min(ans,temp);
                left++;
            }
        }
        return ans==INT_MAX? -1:ans;
    }
};