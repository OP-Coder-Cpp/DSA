#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0,right=0;

        int totalSum=0;
        for(int num:nums)
            totalSum+=num;
        
        int target=totalSum-x;
        if (target <0) return -1;
        if(target ==0) return nums.size();

        int arrsum=0;
        int ans=INT_MIN;
        for(;right<nums.size();right++)
        {
            arrsum+=nums[right];

            while(left<=right && arrsum>target){
                arrsum-=nums[left];
                left++;
            }
            if(arrsum==target)
                ans=max(ans,right-left+1);
        }
        if (ans!=INT_MIN){
            return nums.size()-ans;
        }
        return -1;
    }
};