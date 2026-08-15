from typing import List
class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        xr=0
        count=0

        for num in nums:
            xr^=num
            if(num!=0):
                count+=1

        if(xr!=0):
            return len(nums)
        elif(count>0):
            return len(nums)-1
        
        return 0
