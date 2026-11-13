#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=nums[0];
        for(int num:nums){
            if(mx<num)
                mx=num;
        }
        int ans=0;
        for(int num:nums){
            ans+=abs(mx-num);
        }
        return ans;
    }
};