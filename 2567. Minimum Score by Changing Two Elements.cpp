#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();

        if(n==3)
            return 0;

        
        sort(nums.begin(),nums.end());
        int temp1=nums[0];
        int temp2=nums[1];
        int ans=INT_MAX;
        nums[0]=nums[2];
        nums[1]=nums[2];

        ans=min(ans,nums[n-1]-nums[0]);

        nums[0]=temp1;
        nums[1]=temp2;

        temp1=nums[n-1];
        temp2=nums[n-2];
        nums[n-1]=nums[n-3];
        nums[n-2]=nums[n-3];

       
        ans=min(ans,nums[n-1]-nums[0]);
        nums[n-1]=temp1;
        nums[n-2]=temp2;

        ans=min(ans,nums[n-2]-nums[1]);
        return ans;
    }
};