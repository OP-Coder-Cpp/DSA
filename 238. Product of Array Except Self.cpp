#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];

        int i=1,j=n-2;
        vector<int> ans(n);

        for(;i<n && j>=0;i++,j--)
        {
            prefix[i]=prefix[i-1]*nums[i];
            suffix[j]=suffix[j+1]*nums[j];
        }
        ans[0]=suffix[1];
        ans[n-1]=prefix[n-2];
        for(int k=1;k<n-1;k++)
        {
            ans[k]=prefix[k-1]*suffix[k+1];
        }
        return ans;

    }
};