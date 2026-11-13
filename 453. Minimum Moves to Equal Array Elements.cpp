#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=nums[0];
        for(int num:nums){
            if(num<mn)
                mn=num;
        }
        int ans=0;
        for(int num:nums)
            ans+=num-mn;
        
        return ans;
    }
};