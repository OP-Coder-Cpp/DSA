#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        int half=n/2;
        long long totalSum=0;

        for(int num:nums)
            totalSum+=num;
        long long firstSum=0;
        for(int i=0;i<half;i++)
            firstSum+=nums[i];

        for(int i=0;i<n;i++){
            long long secondSum=totalSum-firstSum;

            if(firstSum>secondSum)
                ans++;

            firstSum -= nums[i];
            firstSum += nums[(i + half) % n];
        }
        return ans;
    }
};