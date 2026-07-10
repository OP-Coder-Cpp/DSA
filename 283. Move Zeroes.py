from typing import List
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)

        i=0
        j=0

        while(j<n):
            if nums[j]!=0:
                nums[i]=nums[j]
                i+=1
            j+=1
        j=i
        for i in range (j,n):
            nums[i]=0
        