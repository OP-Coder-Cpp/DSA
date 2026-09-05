from typing import List
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n=len(nums)

        dp=[[0,0] for _ in range(n)]

        mx=nums[0]
        mn=nums[n-1]

        for i in range(n):
            j = n - 1 - i
            mx=max(mx,nums[i])
            dp[i][0]=mx

            mn=min(mn,nums[j])
            dp[j][1]=mn
        for i in range(n):
            if dp[i][0]-dp[i][1]<=k:
                return i
        
        return -1