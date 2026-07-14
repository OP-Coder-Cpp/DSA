from typing import List
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n=len(nums)

        for i in range (1,n):
            nums[i]+=nums[i-1]

        if nums[n-1]-nums[0]==0:
            return 0

        for i in range(1,n):
            if nums[i-1]==(nums[n-1]-nums[i]):
                return i
        
        if nums[n-2]==0:
            return n-1
        return -1