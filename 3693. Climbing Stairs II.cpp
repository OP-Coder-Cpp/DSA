#include<bits/stdc++.h>;
using namespace std;
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> ans(n+1,0);
        int cost=0;
        for(int i=1;i<=n;i++)
        {
            int min1,min2,min3;
            min1=min2=min3=INT_MAX;

            if(i-1>=0)
                min1=ans[i-1]+(1*1);
            if(i-2>=0)
                min2=ans[i-2]+(2*2);
            if(i-3>=0)
                min3=ans[i-3]+(3*3);

            ans[i]=costs[i-1]+min(min(min1,min2),min3);
        }
        return ans[n];
    }
};