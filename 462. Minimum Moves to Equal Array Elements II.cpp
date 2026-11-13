#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        if(n&1)
        {
            int ans=0;
            for(int num:nums){
                ans+=abs(nums[n/2]-num);
                
            }
            return ans;
        }
        else
        {
            int ans1=0,ans2=0;
            for(int num:nums){
                ans1+=abs(nums[(n/2)-1]-num);
                ans2+=abs(nums[n/2]-num);
            }
            return min(ans1,ans2);
        }
    }
};