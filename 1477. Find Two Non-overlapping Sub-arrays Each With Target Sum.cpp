#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();

        int INF=1e9;
        vector<int> dp(n+1,INF);

        int left=0;
        int sum=0;
        int ans=INF;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            while(sum>target){
                sum-=arr[left];
                left++;
            }

            dp[i+1]=dp[i];
            if(target==sum){
                int current_size=i-left+1;
                if(dp[left]!=INF){
                    ans=min(ans,current_size+dp[left]);

                }
                dp[i+1]=min(dp[i+1],current_size);
            }
    
        }

        return ans!=INF? ans: -1;
    }
};